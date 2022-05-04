// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    const int total_width = 70;
    const int field_1_width = 20;
    const int field_2_width = 20;
    const int field_3_width = 15;
    const int field_4_width = 15;


    // Display the header ruler and blank lines
    std::string header_ruler = "1234567890";
    std::cout << "\n";
    for (size_t i{0}; i < 7; i++)
        std::cout << header_ruler;
    std::cout << "\n" << std::endl;

    // Display title, centered under the ruler
    int title_length = tours.title.length();
    std::cout << std::setw((total_width - title_length)/2) << std::setfill('-') << "";
    std::cout << tours.title;
    if (title_length % 2 != 0) // account for even or odd length title
        std::cout << std::setw((total_width - title_length)/2 + 1) << std::setfill('-') << "" << "\n" << std::endl;
    else
        std::cout << std::setw((total_width - title_length)/2) << std::setfill('-') << "" << "\n" << std::endl;


    // Display table header:
    std::cout << std::setfill(' ');
    std::cout << std::setw(field_1_width) << std::left << "Country"
              << std::setw(field_2_width) << std::left << "City"
              << std::setw(field_3_width) << std::left << "Population"
              << std::setw(field_4_width) << std::right << "Price" << std::endl;
    // Display the dashes below the table header
    std::cout << std::string(total_width, '-') << std::endl;

    for(auto country : tours.countries) {   // loop through the countries
        size_t count = 0;
        for(auto city : country.cities) {       // loop through the cities for each country
            if (count == 0)
                std::cout << std::setw(field_1_width) << std::left << country.name;
            else
                std::cout << std::setw(field_1_width) << std::left << "";

            std::cout << std::setw(field_2_width) << std::left << city.name
                      << std::setw(field_3_width) << std::right
                      << std::setprecision(3) << std::scientific << std::uppercase << city.population
                      << std::setw(field_4_width) << std::right << std::setprecision(2) << std::fixed << city.cost
                      << std::endl;
            count++;
        }
    }
    std::cout << std::endl << std::endl;
    return 0;
}