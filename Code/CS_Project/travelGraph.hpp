#pragma once

#include <string>
#include <vector>
#include <cmath>

using namespace std;

class TravelGraph {
    public:

    // airport struct
    struct airport {
        int id;
        double latitude;
        double longitude;

        string city; // for trip planner
        string country; // for trip planner
    };

    // graph node
    struct node {
        airport current;
        airport* next;
        double dist;
    };

    // member functions
    TravelGraph(); // constructor (makes a travel graph object)
    double distanceBetween(airport a1, airport a2) const;

    private:
    vector<airport*> adjList;
};