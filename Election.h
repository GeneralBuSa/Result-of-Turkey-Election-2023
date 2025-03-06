#ifndef ELECTION_H
#define ELECTION_H

#include <iostream>
#include <string>
using namespace std;

class Election {
public:
    int whatDoYouWant();
    int checkWhatDoYouWant(int wanted);
    int checkPlaqueNumber(int city_plaque);
    void setPlaque(int a);
protected:
    int city_plaque;
    int wanted;
};

#endif