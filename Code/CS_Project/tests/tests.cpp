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
{"21","Sault Sainte Marie","Canada","46.48500061035156","-84.5093994140625","airport"}
{"22","Winnipeg","Canada","50.0564002991","-97.03250122070001","airport"}
{23,"Halifax / CFB Shearwater Heliport","Halifax","Canada",\N,"CYAW",44.639702,-63.499401,144,-4,"A","America/Halifax","airport","OurAirports"}
{24,"St. Anthony Airport","St. Anthony","Canada","YAY","CYAY",51.3918991089,-56.083099365200006,108,-3.5,"A","America/St_Johns","airport","OurAirports"}
{25,"Tofino / Long Beach Airport","Tofino","Canada","YAZ","CYAZ",49.079833,-125.775583,80,-8,"A","America/Vancouver","airport","OurAirports"}
{26,"Kugaaruk Airport","Pelly Bay","Canada","YBB","CYBB",68.534401,-89.808098,56,-7,"A","America/Edmonton","airport","OurAirports"}
{27,"Baie Comeau Airport","Baie Comeau","Canada","YBC","CYBC",49.13249969482422,-68.20439910888672,71,-5,"A","America/Toronto","airport","OurAirports"}
{28,"CFB Bagotville","Bagotville","Canada","YBG","CYBG",48.33060073852539,-70.99639892578125,522,-5,"A","America/Toronto","airport","OurAirports"}
{29,"Baker Lake Airport","Baker Lake","Canada","YBK","CYBK",64.29889678960001,-96.077796936,59,-6,"A","America/Winnipeg","airport","OurAirports"}
{30,"Campbell River Airport","Campbell River","Canada","YBL","CYBL",49.950801849365234,-125.27100372314453,346,-8,"A","America/Vancouver","airport","OurAirports"}
{31,"Brandon Municipal Airport","Brandon","Canada","YBR","CYBR",49.91,-99.951897,1343,-6,"A","America/Winnipeg","airport","OurAirports"}
{32,"Cambridge Bay Airport","Cambridge Bay","Canada","YCB","CYCB",69.1081008911,-105.138000488,90,-7,"A","America/Edmonton","airport","OurAirports"}
{33,"Nanaimo Airport","Nanaimo","Canada","YCD","CYCD",49.054970224899996,-123.869862556,92,-8,"A","America/Vancouver","airport","OurAirports"}
{34,"Castlegar/West Kootenay Regional Airport","Castlegar","Canada","YCG","CYCG",49.2963981628,-117.632003784,1624,-8,"A","America/Vancouver","airport","OurAirports"}
{35,"Miramichi Airport","Chatham","Canada","YCH","CYCH",47.007801,-65.449203,108,-4,"A","America/Halifax","airport","OurAirports"}
{36,"Charlo Airport","Charlo","Canada","YCL","CYCL",47.990799,-66.330299,132,-4,"A","America/Halifax","airport","OurAirports"}
{37,"Kugluktuk Airport","Coppermine","Canada","YCO","CYCO",67.816704,-115.143997,74,-7,"A","America/Edmonton","airport","OurAirports"}
{38,"Coronation Airport","Coronation","Canada","YCT","CYCT",52.0750007629,-111.444999695,2595,-7,"A","America/Edmonton","airport","OurAirports"}
{39,"Chilliwack Airport","Chilliwack","Canada","YCW","CYCW",49.1528015137,-121.939002991,32,-8,"A","America/Vancouver","airport","OurAirports"}
{40,"Clyde River Airport","Clyde River","Canada","YCY","CYCY",70.4860992432,-68.5167007446,87,-5,"A","America/Toronto","airport","OurAirports"}
}
1,3,4,7,8,14