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
        

        int id;
        double latitude;
        double longitude;

        string city; // for trip planner
        string country; // for trip planner
    };

    // // graph node
    // struct node {
    //     airport current;
    //     airport* next;
    //     double dist;
    // };

    // member functions
    TravelGraph(); // constructor (makes a travel graph object)
    double distanceBetween(airport a1, airport a2) const;

    private:
    map<airport, vector<pair<airport, double>>> adjLists;

    vector<airport> cleanAirportData(string fileInfo);
    vector<pair<string, string>> cleanRouteData(string fileInfo);
};