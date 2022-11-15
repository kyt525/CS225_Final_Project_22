#include "travelGraph.hpp"
#define PI 3.1415926535897932846
#define RADIO_TERRESTRE 6372797.56085

float TravelGraph::ShortestDist(Airport a1, Airport a2) {
    int R = 6371; // Radius of the Earth
    float lat = (a2.latitude * PI/ 180) - (a1.latitude * PI/180); // in radians
    float lon = (a2.longitude * PI/180) - (a1.longitude * PI/180);
    
    double x = sin(lat/2) * sin(lat/2) + (cos(a2.latitude * PI/180) * cos(a1.latitude * PI/180) * sin(lon/2) * sin(lon/2));
    double y = 2 * atan2(sqrt(x), sqrt(1 - x));

    double dist = RADIO_TERRESTRE * y;\

    return dist;
}