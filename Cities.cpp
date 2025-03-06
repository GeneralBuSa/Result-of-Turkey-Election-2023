#include "Cities.h"

void Cities::setCities() {
    for (int i = 0; i < 81; i++) {
        cout << cities[i] << " : " << i + 1 << " ";
        if ((i + 1) % 12 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}
