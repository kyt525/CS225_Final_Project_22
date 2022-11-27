#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>
#include <map>
#include <cassert>
#include <fstream>

using namespace std;

class TravelGraph {
    public:
    TravelGraph(const string& airportData, const string& routeData); // input a file (?)
    vector<airport> cleanAirportData(string fileInfo);
    vector<airport> cleanRouteData(string fileInfo);

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


// universal functions (may need another file though)
string file_to_string(const string& filename);
int SplitString(const string & str1, char sep, vector<string> &fields);
string TrimRight(const std::string & str);
string TrimLeft(const std::string & str);
string Trim(const string & str);

