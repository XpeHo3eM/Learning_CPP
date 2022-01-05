#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"


void createJSON()
{
	std::ofstream file("movies.json");
	nlohmann::json json = {
		{ "21 jump street",	{
			{"country",  "USA"},
			{"date",     "12.03.2012"},
			{"studio",   {
				"Columbia Pictures",
				"Metro-Goldwyn-Mayer"
			}} ,
			{"edited", {
				"Jonah Hill",
				"Michael Bacall"
			}},
			{"director", {
				"Phil Lord",
				"Christopher Miller"
			}},
			{"producer", {
				"Neal H. Moritz",
				"Stephen J. Cannell"
			}},
			{"starring", {
				{"Jonah Hill",     "Morton Shmidt"},
				{"Channing Tatum", "Greg Jengo"},
				{"Brie Larson",    "Molly"},
				{"Dave Franco",    "Eric"}
				}
			}
		  } 
		}, 

		{ "21 and Over", {
			{"country",  "USA"},
			{"date",     "01.03.2013"},
			{"studio",   "Relativity Media"},
			{"edited",   "John Refoua"},
			{"director", {
				"Jon Lucas",
				"Scott Moore"
			}},
			{"producer", {
				"David Hoberman",
				"Ryan Kavanaugh",
				"Todd Lieberman"
			}},
			{"starring", {
				{"Miles Teller", "Miller"},
				{"Skylar Astin", "Casey"},
				{"Justin Chon",  "Jeff Chang"},
				{"Sarah Wright", "Nicole"}
				}
			}
		  } 
		},

		{ "The tomorrow war", {
			{"country", "USA"},
			{"date",    "02.07.2020"},
			{"studio",  {
				"Paramount Pictures",
				"Skydance Media"
			}},
			{"edited", {
				"Roger Barton",
				"Garret Elkins"
			}},
			{"director", "Chris McKay"},
			{"producer", {
				"David Ellison",
				"Dana Goldberg",
				"Don Granger"
			}},
			{"starring", {
				{"Chris Pratt",       "James Daniel"},
				{"Yvonne Strahovski", "Colonel Muri"},
				{"Betty Gilpin",      "Emmy Forester"},
				{"Sam Richardson",    "Charlie"}
				}
			}
		  } 
		},

		{ "Titanic", {
			{"country", "USA"},
			{"date",    "19.12.1997"},
			{"studio",  {
				"Paramount Pictures",
				"20th Century Fox"
			}},
			{"edited", {
				"Conrad Buff",
				"James Cameron",
				"Richard A. Harris"
			}},
			{"director", "James Cameron"},
			{"producer", {
				"James Cameron",
				"Jon Landau"
			}},
			{"starring", {
				{"Leonardo DiCaprio", "Jack Dawson"},
				{"Kate Winslet",      "Rose DeWitt Bukater"},
				{"Billy Zane",        "Cal Hockley"},
				{"Gloria Stuart",     "Rose Dawson Calvert"}
				}
			}
		  } 
		},

		{ "Inception", {
			{"country",  "USA"},
			{"date",     "16.07.2010"},
			{"studio",   "Warner Bros. Pictures"},
			{"edited",   "Lee Smith"},
			{"director", "Christopher Nolan"},
			{"producer", {
				"Emma Thomas",
				"Christopher Nolan"
			}},
			{"starring", {
				{"Leonardo DiCaprio", "Dom Cobb"},
				{"Ken Watanabe",      "Mr. Saito"},
				{"Elliot Page",       "Ariadne"},
				{"Marion Cotillard",  "Mal Cobb"}
				}
			}
		  } 
		}
	};

	file << json;
	file.close();
}