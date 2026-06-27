#ifndef CITIES_H
#define CITIES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct PartyVote {
    string name;
    string percentage;
};

struct CityData {
    string name;
    string mayor;
    string winnerParty;
    vector<PartyVote> votes;
};

class Cities {
public:
    static void setCities();
    static bool loadElectionData(const string& filename);
    static void printCitiesByWinnerParty(const string& partyName);
    static void printGeneralStatistics();
protected:
    static map<int, CityData> cities_data;
};

#endif