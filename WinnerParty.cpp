#include "WinnerParty.h"

void WinnerParty::Party() {
    auto it = cities_data.find(city_plaque);
    if (it != cities_data.end()) {
        cout << "Winner Party of " << it->second.name << ": " << it->second.winnerParty << endl;
    } else {
        cout << "Please enter valid number(1-81)" << endl;
    }
}
