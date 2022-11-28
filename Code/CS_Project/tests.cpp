TEST_CASE("read data 1") {
    V2D roster = file_to_V2D("../tests/data/c5_s10_3_roster.csv");

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

TEST_CASE("distance 1") {

    TravelGraph::airport a1 = {.id = 0, .latitude = 53.32055555555556, .longitude = -1.7297222222222221, .city = "", .country = ""};
    TravelGraph::airport a2 = {.id = 1, .latitude = 53.31861111111111, .longitude = -1.6997222222222223, .city = "", .country = ""};

    double distance = TravelGraph::distanceBetween(a1, a2);

    const double correct distance = 

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
