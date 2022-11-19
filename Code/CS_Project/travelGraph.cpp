#include "travelGraph.hpp"
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932846
#define EARTH_RADIUS_M 6372797.56085 // radius of Earth in m

double TravelGraph::distanceBetween(airport a1, airport a2) const {
    double lon = (a2.longitude * PI / 180) - (a1.longitude * PI / 180); // in radians
    double lat = (a2.latitude * PI / 180) - (a1.latitude * PI / 180); 
    
    double x = sin(lat / 2) * sin(lat / 2) + (cos(a2.latitude * PI / 180) * cos(a1.latitude * PI / 180) * sin(lon / 2) * sin(lon / 2));
    double y = 2 * atan2(sqrt(x), sqrt(1 - x));

    double dist = EARTH_RADIUS_M * y;

    return dist; 
}