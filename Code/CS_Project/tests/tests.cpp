#include "../cs225/catch/catch.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

#include "../travelGraph.h"
#include "../utils.h"


using namespace std;

// test to see whether the airports data are properly stored and cleaned
// 0 - data cleaned, 1 - size, 2 - id, 3 - city, 4 - country, 5 - latitude, 6 - longitude
int correctAirports(const vector<TravelGraph::airport>& airports, const vector<vector<string>>& answer) {
    

    if(airports.size() != answer.size())
        return 1;
 
    for(int i = 0; i < airports.size(); i++){
        if(airports[i].id != stoi(answer[i][0])){
            return 2;}
        else if(airports[i].city != answer[i][1]){
            return 3;}
        else if(airports[i].country != answer[i][2]){
            return 4;}
        else if(airports[i].latitude >= stod(answer[i][3]) + .001 || airports[i].latitude <= stod(answer[i][3]) - .001){
            return 5;}
        else if(airports[i].longitude >= stod(answer[i][4]) + .001 || airports[i].longitude <= stod(answer[i][4]) - .001 ){
            return 6;}}
    return 0;
}

// test to see whether the routes data are properly stored and cleaned
// 0 - data cleaned, 1 - size, 2 - latitude, 3 - longitude
int correctRoutes(const vector<pair<int, int>>& routes, const vector<vector<int>>& answer) {
    
    if(routes.size() != answer.size())
        return 1;
        
    for(int i = 0; i < routes.size(); i++)
        if(routes[i].first != answer[i][0])
            return 2;
        else if(routes[i].second != answer[i][1])
            return 3;
         
    return 0;
}

int correctDistance(double &distance, const double &answer){
    if(distance > answer + 1 || distance < answer - 1) // adding buffer to online distance calculated vs our formula
        return 1;
    return 0;
}


TEST_CASE("airport data small") {
    TravelGraph g;
    string fileInfo = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/small_airport_test.csv");
    vector<TravelGraph::airport> data = g.cleanAirportData(fileInfo);

    for(int i = 0; i < data.size(); i++){
        cout<< data[i].id << " " <<data[i].city << " " <<data[i].country << " " <<data[i].latitude <<  " " <<data[i].longitude << endl;
    }

    const vector<vector<string>> answer = {
        {"1","\"Goroka\"","\"Papua New Guinea\"","-6.081689834590001","145.391998291"}, \
        {"2","\"Madang\"","\"Papua New Guinea\"","-5.20707988739","145.789001465"}, \
        {"3","\"Mount Hagen\"","\"Papua New Guinea\"","-5.826789855957031","144.29600524902344"}, \
        {"4","\"Nadzab\"","\"Papua New Guinea\"","-6.569803","146.725977"}, \
        {"5","\"Port Moresby\"","\"Papua New Guinea\"","-9.443380355834961","147.22000122070312"}, \
        {"6","\"Wewak\"","\"Papua New Guinea\"","-3.58383011818","143.669006348"}, \
        {"7","\"Narssarssuaq\"","\"Greenland\"","61.1604995728","-45.4259986877"}, \
        {"8","\"Godthaab\"","\"Greenland\"","64.19090271","-51.6781005859"}, \
        {"9","\"Sondrestrom\"","\"Greenland\"","67.0122218992","-50.7116031647"}, \
        {"10","\"Thule\"","\"Greenland\"","76.5311965942","-68.7032012939"} 
        };

    REQUIRE(correctAirports(data, answer) == 0);
}

TEST_CASE("airport data medium") {
    TravelGraph g;
    string fileInfo = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/medium_airport_test.csv");
    vector<TravelGraph::airport> data = g.cleanAirportData(fileInfo);

    for(int i = 0; i < data.size(); i++){
        cout<< data[i].id << data[i].city << data[i].country << data[i].latitude << data[i].longitude << endl;
    }
    
    const vector<vector<string>> answer = {
        {"21","\"Sault Sainte Marie\"", "\"Canada\"","46.485","-84.5094"},\
        {"22","\"Winnipeg\"","\"Canada\"","50.0564","-97.0325"},\
        {"23","\"Halifax\"","\"Canada\"","44.6397","-63.499401"},\
        {"24","\"St. Anthony\"","\"Canada\"","51.3918991089","-56.083099365200006"},\
        {"25","\"Tofino\"","\"Canada\"","49.079833","-125.775583"},\
        {"26","\"Pelly Bay\"","\"Canada\"","68.534401","-89.808098"},\
        {"27","\"Baie Comeau\"","\"Canada\"","49.13249969482422","-68.20439910888672"},\
        {"28","\"Bagotville\"","\"Canada\"","48.33060073852539","-70.99639892578125"},\
        {"29","\"Baker Lake\"","\"Canada\"","64.29889678960001","-96.077796936"},\
        {"30","\"Campbell River\"","\"Canada\"","49.950801849365234","-125.27100372314453"},\
        {"31","\"Brandon\"","\"Canada\"","49.91","-99.951897"},\
        {"32","\"Cambridge Bay\"","\"Canada\"","69.1081008911","-105.138000488"},\
        {"33","\"Nanaimo\"","\"Canada\"","49.054970224899996","-123.869862556"},\
        {"34","\"Castlegar\"","\"Canada\"","49.2963981628","-117.632003784"},\
        {"35","\"Chatham\"","\"Canada\"","47.007801","-65.449203"},\
        {"36","\"Charlo\"","\"Canada\"","47.990799","-66.330299"},\
        {"37","\"Coppermine\"","\"Canada\"","67.816704","-115.143997"},\
        {"38","\"Coronation\"","\"Canada\"","52.0750007629","-111.444999695"},\
        {"39","\"Chilliwack\"","\"Canada\"","49.1528015137","-121.939002991"},\
        {"40","\"Clyde River\"","\"Canada\"","70.4860992432","-68.5167007446"}
        };

    REQUIRE(correctAirports(data, answer) == 0);
}

TEST_CASE("distanceBetween() test1") {

    TravelGraph::airport a1 = {.id = 0, .latitude = 53.32055555555556, .longitude = -1.7297222222222221, .city = "", .country = ""};
    TravelGraph::airport a2 = {.id = 1, .latitude = 53.31861111111111, .longitude = -1.6997222222222223, .city = "", .country = ""};

    TravelGraph g;
    double distance = g.distanceBetween(a1, a2);
    const double correct_distance = 2004.93;

    REQUIRE(correctDistance(distance, correct_distance) == 0);
}

TEST_CASE("read route_small"){
    TravelGraph g;
    string fileInfo = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/small_route_test.csv");
    vector<pair<int,int>> routes  = g.cleanRouteData(fileInfo);


    const vector<vector<int>> answer = {
        {2965,2990}, \
        {2966,2990}, \
        {2966,2962}, \
        {2968,2990}, \
        {2968,4078}, \ 
        {4029,2990}, \
        {4029,6969}, \
        {4029, 0 }, \
        {4029,6160}, \ 
        {6156,2952}, \
    };
    REQUIRE(correctRoutes(routes, answer) == 0);
}

TEST_CASE("read route_medium"){
     TravelGraph g;
    string fileInfo = file_to_string("/workspaces/CS225_Final_Project_22/Code/CS_Project/tests/medium_route_test.csv");
    vector<pair<int,int>> routes  = g.cleanRouteData(fileInfo);

    vector<vector<int>> answer = {
        {6156,2990},\
        {2922,6969},\
        {2952,6156},\
        {2990,2965},\
        {2990,2966},\
        {2990,2968},\
        {2990,4029},\
        {2990,6156},\
        {2990,2948},\
        {2990,2975},\
        {2948,2990},\
        {2948,6969},\
        {2948,6160},\
        {2962,2966},\
        {6969,4029},\
        {6969,2922},\
        {6969,2948},\
        {6969,2975},\
        {2972,2975},\
        {2972,6160}
    };
    REQUIRE(correctRoutes(routes, answer) == 0);

}



// TEST_CASE("BFS Test"){
//     TravelGraph g;


// }

// TEST_CASE("Shortest Path Test"){
//     TravelGraph g;


// }

// TEST_CASE("getCentrality Test"){
//     TravelGraph g;


// }

