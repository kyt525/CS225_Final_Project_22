#pragma once

#include "utils.h"
#include "travelGraph.h"

#include <bits/stdc++.h>

using namespace std;

class BFS{
    public:
    // initalize the BFS with the given graph  
    BFS(const vector<pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>> adj);

    // using BFS to traverse through every airport in the dataset, while printing its id
    vector<int> allAirports(TravelGraph graph, TravelGraph::airport source);

    private:
    // vector of pairs: in the pair, the first value is the source airport, and the second is a vector that 
    // holds destination airports and their distances from the source.
    vector<pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>> adjLists;
    // a helper function to get the adjacency list of the airport
    pair<TravelGraph::airport, vector<pair<TravelGraph::airport, double>>>* find(const int a1);
};
