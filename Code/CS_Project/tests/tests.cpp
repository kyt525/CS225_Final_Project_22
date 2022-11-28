TEST_CASE("read data 1") {
    V2D roster = cleanAirportData("../tests/medium_airport_test.csv");

    const V2D correct_roster = {{"CS577", "JydY", "MnWd", "tnkL"},\
     {"CS591", "gpDS", "94Ol", "tnkL"}, \
     {"CS386", "SjC0", "EYge", "Nvu1"}, \
     {"CS500", "MnWd", "uAcT", "EYge"}, \
     {"CS395", "gpDS", "EYge", "MnWd"}
     };

    REQUIRE(roster == correct_roster);

    V2D students = file_to_V2D("../tests/data/c5_s10_3_students.csv");

    const V2D answer = {
        {"JydY", "CS577"}, \
        {"MnWd", "CS577", "CS500", "CS395"}, \
        {"tnkL", "CS577", "CS591"}, \
        {"gpDS", "CS591", "CS395"}, \
        {"94Ol", "CS591"}, \
        {"SjC0", "CS386"}, \
        {"EYge", "CS386", "CS500", "CS395"}, \
        {"Nvu1", "CS386"}, \
        {"uAcT", "CS500"}
        };
    REQUIRE(students == answer);
}

TEST_CASE("distanceBetween() test1") {

    TravelGraph::airport a1 = {.id = 0, .latitude = 53.32055555555556, .longitude = -1.7297222222222221, .city = "", .country = ""};
    TravelGraph::airport a2 = {.id = 1, .latitude = 53.31861111111111, .longitude = -1.6997222222222223, .city = "", .country = ""};

    double distance = TravelGraph::distanceBetween(a1, a2);

    const double correct_distance = 2010.8909946870748

    REQUIRE(distance == correct_distance);
}


const V2D answer = { 
{21,"Sault Sainte Marie","Canada",46.48500061035156,-84.5093994140625}
{22,"Winnipeg","Canada",50.0564002991,-97.03250122070001}
{23,"Halifax","Canada",44.639702,-63.499401}
{24,"St. Anthony","Canada",51.3918991089,-56.083099365200006}
{25,"Tofino","Canada",49.079833,-125.775583}
{26,"Pelly Bay","Canada",68.534401,-89.808098}
{27,"Baie Comeau","Canada",49.13249969482422,-68.20439910888672}
{28,"Bagotville","Canada,48.33060073852539,-70.99639892578125}
{29,"Baker Lake","Canada",64.29889678960001,-96.077796936}
{30,"Campbell River","Canada",49.950801849365234,-125.27100372314453}
{31,"Brandon","Canada",49.91,-99.951897}
{32,"Cambridge Bay","Canada",69.1081008911,-105.138000488}
{33,"Nanaimo","Canada",49.054970224899996,-123.869862556}
{34,"Castlegar","Canada",49.2963981628,-117.632003784}
{35,"Chatham","Canada",47.007801,-65.449203}
{36,"Charlo","Canada",47.990799,-66.330299}
{37,"Coppermine","Canada",67.816704,-115.143997}
{38,"Coronation","Canada",52.0750007629,-111.444999695}
{39,"Chilliwack","Canada",49.1528015137,-121.939002991}
{40,"Clyde River","Canada",70.4860992432,-68.5167007446}
}
1,3,4,7,8,14