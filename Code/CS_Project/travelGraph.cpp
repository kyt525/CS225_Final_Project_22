#include <bits/stdc++.h>

#include "travelGraph.h"
#include "utils.h"

using namespace std;

#define PI 3.1415926535897932846
#define EARTH_RADIUS_M 6372797.56085 // radius of Earth in m

TravelGraph::TravelGraph(){}

// privat function that works like map() find and returns the 
pair<TravelGraph::airport, VP>* TravelGraph::find(const TravelGraph::airport& a1) {
    for (unsigned i = 0; i < adjLists.size(); i++) {
        TravelGraph::airport a2 = adjLists.at(i).first;
        if ((a1.id == a2.id) && (a1.latitude == a2.latitude) && (a1.longitude == a2.longitude) && (a1.city == a2.city) && (a1.country == a2.country)) {
            return &adjLists.at(i);
        }
    }
}

bool TravelGraph::airport::operator <(const TravelGraph::airport& other) {
    if (id < other.id) {
        return true;
    }
    return false;
}


TravelGraph::TravelGraph(const string& airportData, const string& routeData) {
    string fileInfo1 = file_to_string(airportData);
    vector<TravelGraph::airport> airports = cleanAirportData(fileInfo1); // list of airports
    string fileInfo2 = file_to_string(routeData);
    vector<pair<int,int>> routes = cleanRouteData(fileInfo2); // whether an airport is adjacent to the other: in airport ids

    // creating a graph
    for (unsigned i = 0; i < airports.size(); i++) {
        pair<TravelGraph::airport, VP> temp(airports.at(i), VP());
        adjLists.push_back(temp);
    }

    for (unsigned j = 0; j < routes.size(); j++) {
        // bools to check whether the source and destination airports in the route are also in the airpots list
        bool validSource = false;
        bool validDest = false;

        int sourceID = routes.at(j).first;
        int destID = routes.at(j).second;

        // need to create new airport objects to add to the graph
        TravelGraph::airport source;
        TravelGraph::airport dest;
        source.id = sourceID;
        dest.id = destID;
        for (unsigned k = 0; k < airports.size(); k++) {
            // airport curr = airports.at(k);
            if (airports.at(k).id == sourceID) {
                validSource = true;
                // finish defining the SOURCE airport
                source.latitude = airports.at(k).latitude;
                source.longitude = airports.at(k).longitude;
                source.city = airports.at(k).city;
                source.country = airports.at(k).country;
            }
            if (airports.at(k).id == destID) {
                validDest = true;
                // finish defining the DEST airport
                dest.latitude = airports.at(k).latitude;
                dest.longitude = airports.at(k).longitude;
                dest.city = airports.at(k).city;
                dest.country = airports.at(k).country;
            }
        }

        if (validSource && validDest) {
            pair<TravelGraph::airport, double> flight(dest, distanceBetween(source,dest)); // make a pair of (dest, distance)
            find(source)->second.push_back(flight); // add pair to respective source's adjList
        }
    }
    
}

vector<pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>> TravelGraph::getAdjLists() {
    return adjLists;
}

vector<pair<TravelGraph::airport, double>> TravelGraph::getAdjacent(TravelGraph::airport source) { 
    return find(source)->second;
}

// helper function to find the distance between two airports: returns distance as a double
double TravelGraph::distanceBetween(TravelGraph::airport a1, TravelGraph::airport a2) const {
    double lon = (a2.longitude * PI / 180) - (a1.longitude * PI / 180); // in radians
    double lat = (a2.latitude * PI / 180) - (a1.latitude * PI / 180); 
    
    double x = sin(lat / 2) * sin(lat / 2) + (cos(a2.latitude * PI / 180) * cos(a1.latitude * PI / 180) * sin(lon / 2) * sin(lon / 2));
    double y = 2 * atan2(sqrt(x), sqrt(1 - x));

    double dist = EARTH_RADIUS_M * y;

    return dist; 
}

// cleaning airport data by only keeping the 0th (airport ID), 2nd (city), 3rd (country), 6th (latitude), 7th (longitude), 13th (type)
// helper that returns vector of airports
vector<TravelGraph::airport> TravelGraph::cleanAirportData(const string& fileInfo) {
    vector<TravelGraph::airport> airports;
    vector<string> entries; // airport entries: each entry is a string with airport details separated by commas
    int numRows = SplitString(fileInfo, '\n', entries);

    for (int row = 0; row < numRows; row++) {
        TravelGraph::airport a; // each entry = details of an airport
        bool validAirport = true;
        vector<string> details; // each detail in string form (need to turn id into a int and lat, log to decimals)
        
        int numCols = SplitString(entries.at(row), ',', details);
        for (int col = 0; col < numCols; col++) {
            string detail = Trim(details.at(col));
            // only keeping the 0th (airport ID), 2nd (city), 3rd (country), 6th (latitude), 7th (longitude), 12th (type)
            if (col == 0) {
                std::cout << detail << std::endl;
                a.id = stoi(detail);
                }

            else if (col == 2) {
                a.city = detail;
                }

            else if (col == 3) {
                a.country = detail;
            }
            else if (col == 6)
                a.latitude = stod(detail);

            else if (col == 7)
                a.longitude = stod(detail);

            else if ((col == 12) && (detail != "\"airport\"")){
                validAirport = false;
                }
        }

        if (validAirport) {
            airports.push_back(a);}
    }
    
    return airports;
}

// cleaning routes data by only keeping the 4th (source airport ID), 6th (destination airport id), 8th (stops - only keeping direct flights i.e 0 stops)
// helper that returns vector of airport id (int) pairs 
vector<pair<int, int>> TravelGraph::cleanRouteData(string fileInfo) {
    vector<pair<int, int>> routes;
    vector<string> entries; // airport entries: each entry is a string with airport details separated by commas
    
    int numRows = SplitString(fileInfo, '\n', entries);
    for (int row = 0; row < numRows; row++) {
        pair<int, int> route; // each entry = details of a route
        bool validRoute = true;
        vector<string> details; // each detail in string form (need to turn ids into ints)
        
        int numCols = SplitString(entries.at(row), ',', details);
        for (int col = 0; col < numCols; col++) {
            string detail = Trim(details.at(col));
            // only keeping the 3th (source airport ID), 5th (destination airport id), 7th (stops)
            if (col == 3)
                route.first = stoi(detail);

            else if (col == 5)
                route.second = stoi(detail);

            else if ((col == 7) && (stoi(detail) != 0))
                validRoute = false;
        }//if no destination airport ID then delete entry

        if (validRoute)
            routes.push_back(route);
    }

    return routes;
}
