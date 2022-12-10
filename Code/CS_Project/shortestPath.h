#pragma once

#include "utils.h"
#include "travelGraph.h"

#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>

using namespace std;


//shortestPath algorithms
double shortestDistance(VP shortestPath);
// return the airports in between the source and destination as a vector<pair<destination airport, distance from previous>>
VP shortestPath(TravelGraph graph, TravelGraph::airport source, TravelGraph::airport destination); 

//centrality algorithms 
double betweennessCentrality(TravelGraph graph, TravelGraph::airport node);


