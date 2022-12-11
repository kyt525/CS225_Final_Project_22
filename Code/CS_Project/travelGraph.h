#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>
#include <map>
#include <cassert>
#include <fstream>

#include "utils.h"

using namespace std;

class TravelGraph {
    public:
    TravelGraph(const string& airportData, const string& routeData); // input data files

    // airport struct
    struct airport {
        //functions
        //bool operator<(const airport& other);

        //variables
        int id;
        double latitude;
        double longitude;
        string city; // for trip planner
        string country; // for trip planner
    };

    // member functions
    TravelGraph(); // constructor (makes a travel graph object)
    double distanceBetween(airport a1, airport a2) const;
    vector<airport> cleanAirportData(const string& fileInfo);
    vector<pair<int, int>> cleanRouteData(string fileInfo);
    vector<pair<airport, vector<pair<airport, double>>>> getAdjLists();
    vector<pair<airport, double>> getAdjacent(airport source);
    pair<airport, vector<pair<airport, double>>>* find(const int& a1);

    private:
    // vector of pairs: in the pair, the first value is the source airport, and the second is a vector that 
    // holds destination airports and their distances from the source.
    vector<pair<airport, vector<pair<airport, double>>>> adjLists;
    pair<airport, vector<pair<airport, double>>>* find(const airport& a1);
    
};

typedef vector<pair<TravelGraph::airport, double>> VP;