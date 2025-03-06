#include "Election.h"

int Election::whatDoYouWant() {
    cout << "1: Mayor of City  2: Winner Party of City  3: Percent of All Parties  4: Exit" << endl;
    cout << "Which result do you want to see? Please enter 1-4: " << endl;
    cin >> wanted;
    return wanted;
}

int Election::checkWhatDoYouWant(int wanted) {
    return (wanted >= 1 && wanted <= 4) ? 1 : 0;
}

int Election::checkPlaqueNumber(int city_plaque) {
    return (city_plaque >= 1 && city_plaque <= 81) ? 1 : 0;
}

void Election::setPlaque(int a) {
    city_plaque = a;
}
