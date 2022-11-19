#include "travelGraph.hpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    TravelGraph::airport a1 = {.id = 0, .latitude = 53.32055555555556, .longitude = -1.7297222222222221, .city = "", .country = ""};
    TravelGraph::airport a2 = {.id = 1, .latitude = 53.31861111111111, .longitude = -1.6997222222222223, .city = "", .country = ""};

    cout << setprecision(15) << fixed;
    cout << TravelGraph::distanceBetween(a1, a2) << " M";
 
    return 0;
}