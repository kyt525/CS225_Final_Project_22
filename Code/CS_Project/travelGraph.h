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
    //TravelGraph();
    TravelGraph(const string& airportData, const string& routeData); // input data files

    // airport struct
    struct airport {
        bool operator<(const airport& other);
        // bool operator==(airport& other);
        // bool operator <(const airport& air1, const airport& air2);

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
    vector<airport> cleanAirportData(string fileInfo);
    vector<pair<int, int>> cleanRouteData(string fileInfo);

    private:
    vector<pair<airport, vector<pair<airport, double>>>> adjLists;
    
    // vector<airport> cleanAirportData(string fileInfo);
    // vector<pair<int, int>> cleanRouteData(string fileInfo);
    pair<airport, vector<pair<airport, double>>>* find(const airport& a1);
    
};

typedef vector<pair<TravelGraph::airport, double>> VP;