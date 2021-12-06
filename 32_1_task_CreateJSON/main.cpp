#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"


int main()
{
    std::ofstream file ("film.json");
    nlohmann::json myJSON = { 
        {"name",     "21 jump street"},

        {"country",  "USA"},

        {"date",     "12.03.2012"},

        {"studio",   "Sony Pictures"},

        {"author",   "Jonah Hill"},

        {"director", {"Phil Lord", 
                      "Christopher Miller"}},

        {"producer", {"Neal H. Moritz", 
                      "Stephen Cannell"}},

        {"starring", {{"Morton Shmidt", "Jonah Hill"},
                      {"Greg Jengo",    "Channing Tatum"},
                      {"Molly",         "Brie Larson"},
                      {"Eric",          "Dave Franco"}}}
    };

    file << myJSON;
}
