#include "travelGraph.h"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    TravelGraph g;
    string fileInfo = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/small_airport_test.csv");
    vector<TravelGraph::airport> data = g.cleanAirportData(fileInfo);
    
    string fileInfo2 = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/small_route_test.csv");
    vector<pair<int,int>> data2  = g.cleanRouteData(fileInfo2);
    std::cout<< data2.size() << std::endl;
}