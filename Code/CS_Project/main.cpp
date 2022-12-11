#include "travelGraph.h"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    TravelGraph g;
    //string file = "1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
    string fileInfo = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/small_airport_test.csv");
    // std::cout << "fileInfo: " << fileInfo << std::endl;
    vector<TravelGraph::airport> data = g.cleanAirportData(fileInfo);

    std::cout<< data.size() << std::endl;
}