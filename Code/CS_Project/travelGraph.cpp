#include "travelGraph.hpp"
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932846
#define EARTH_RADIUS_M 6372797.56085 // radius of Earth in m

TravelGraph::TravelGraph(const string& airportData, const string& routeData) {
    string fileInfo = file_to_string(airportData);
    vector<airport> airports = cleanAirportData(fileInfo);
    // creating a graph
}

double TravelGraph::distanceBetween(airport a1, airport a2) const {
    double lon = (a2.longitude * PI / 180) - (a1.longitude * PI / 180); // in radians
    double lat = (a2.latitude * PI / 180) - (a1.latitude * PI / 180); 
    
    double x = sin(lat / 2) * sin(lat / 2) + (cos(a2.latitude * PI / 180) * cos(a1.latitude * PI / 180) * sin(lon / 2) * sin(lon / 2));
    double y = 2 * atan2(sqrt(x), sqrt(1 - x));

    double dist = EARTH_RADIUS_M * y;

    return dist; 
}

string file_to_string(const std::string& filename){ 
  ifstream text(filename);

  stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    string str = str1;
    string::size_type pos;
    while((pos=str.find(sep)) != string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}

string TrimRight(const string & str) {
    string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

string TrimLeft(const string & str) {
    string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

string Trim(const string & str) {
    string tmp = str;
    return TrimLeft(TrimRight(str));
}

// need to clean string by only keeping the 0th (airport ID), 2nd (city), 3rd (country), 6th (latitude), 7th (longitude), 13th (type)
// helper that returns vector of airports
vector<airport> TravelGraph::cleanAirportData(string fileInfo) {
    vector<airport> airports;
    vector<string> entries; // airport entries: each entry is a string with airport details separated by commas
    int numRows = SplitString(fileInfo, '\n', entries);
    for (int row = 0; row < numRows; row++) {
        airport a; // each entry = details of an airport
        bool validAirport = true;
        vector<string> details; // each detail in string form (need to turn id into a int and lat, log to decimals)
        int numCols = SplitString(entries.at(row), ',', details);
        for (int col = 0; col < numCols; col++) {
            string detail = Trim(details.at(col));
            // only keeping the 0th (airport ID), 2nd (city), 3rd (country), 6th (latitude), 7th (longitude), 13th (type)
            if (col == 0) {
                int convertedDetail = stoi(detail);
                a.id = convertedDetail;
            }

            if (col == 2) {
                a.city = detail;
            }

            if (col == 3) {
                a.country = detail;
            }

            if (col == 6) {
                double convertedDetail = stod(detail);
                a.latitude = convertedDetail;
            }

            if (col == 7) {
                double convertedDetail = stod(detail);
                a.longitude = convertedDetail;
            }

            if ((col == 13) && (detail != "airport")) {
                validAirport = false;
            }
        }

        if (validAirport) {
            airports.push_back(a);
        }
    }
    return airports;
}
