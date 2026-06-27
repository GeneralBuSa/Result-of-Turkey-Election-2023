#include "Mayority.h"

void Mayority::Mayor() {
    auto it = cities_data.find(city_plaque);
    if (it != cities_data.end()) {
        cout << "Mayor of " << it->second.name << " : " << it->second.mayor << endl;
    } else {
        cout << "Please enter valid number(1-81)" << endl;
    }
}