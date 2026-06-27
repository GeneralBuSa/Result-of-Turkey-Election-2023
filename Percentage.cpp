#include "Percentage.h"

void Percentage::percentage() {
    auto it = cities_data.find(city_plaque);
    if (it != cities_data.end()) {
        cout << it->second.name << " :" << endl;
        for (const auto& vote : it->second.votes) {
            cout << vote.name << ": " << vote.percentage << " " << endl;
        }
    } else {
        cout << "Please enter valid number(1-81)" << endl;
    }
}
