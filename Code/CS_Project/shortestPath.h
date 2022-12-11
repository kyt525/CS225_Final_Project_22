#pragma once

#include "utils.h"
#include "travelGraph.h"

#include <bits/stdc++.h>

using namespace std;

class shortestPath {
    public:

    // return the airports in between the source and destination as a vector<pair<destination airport, distance from previous>>
    VP Dijkastra(TravelGraph graph, TravelGraph::airport source, TravelGraph::airport destination); 

    //centrality algorithms 
    double betweennessCentrality(TravelGraph graph, TravelGraph::airport node);

    private:
    //shortestPath algorithms
    double shortestDistance(VP shortestPath);
};

