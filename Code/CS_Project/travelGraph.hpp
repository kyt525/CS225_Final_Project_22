#pragma once

#include <string>
#include <vector>
#include <cmath>

using namespace std;

class TravelGraph {
    public:

    // airport struct
    struct Airports {
        int id;
        float latitude;
        float longitude;

        string city; // for trip planner
        string country; // for trip planner
    };

    // graph node
    struct Node {
        Airport airport;
        Airport* next;
        float dist;
    };

    // member functions
    TravelGraph(); // constructor (makes a travel graph object)
    float ShortestDist(Airport a1, Airport a2) const;

    private:
    vector<Airport*> adjList;

};