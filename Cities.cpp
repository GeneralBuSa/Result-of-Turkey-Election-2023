#include "Cities.h"
#include <fstream>
#include <sstream>

map<int, CityData> Cities::cities_data;

void Cities::setCities() {
    int count = 0;
    for (const auto& pair : cities_data) {
        cout << pair.second.name << " : " << pair.first << " ";
        count++;
        if (count % 12 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

bool Cities::loadElectionData(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening data file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string item;
        
        if (!getline(ss, item, ';')) continue;
        int plaque = stoi(item);
        
        CityData data;
        
        if (!getline(ss, data.name, ';')) continue;
        if (!getline(ss, data.mayor, ';')) continue;
        if (!getline(ss, data.winnerParty, ';')) continue;
        
        string votesStr;
        if (getline(ss, votesStr)) {
            stringstream votesSS(votesStr);
            string votePair;
            while (getline(votesSS, votePair, ',')) {
                size_t colonPos = votePair.find(':');
                if (colonPos != string::npos) {
                    PartyVote pv;
                    pv.name = votePair.substr(0, colonPos);
                    pv.percentage = votePair.substr(colonPos + 1);
                    data.votes.push_back(pv);
                }
            }
        }
        
        cities_data[plaque] = data;
    }
    file.close();
    return true;
}

void Cities::printCitiesByWinnerParty(const string& partyName) {
    cout << "\n--- Cities won by " << partyName << " ---\n";
    bool found = false;
    for (const auto& pair : cities_data) {
        if (pair.second.winnerParty == partyName) {
            cout << pair.second.name << " (Plaque: " << pair.first << ")" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No cities found won by party: " << partyName << endl;
    }
}

void Cities::printGeneralStatistics() {
    cout << "\n--- Turkey General Election 2023 Statistics ---\n";
    
    map<string, int> partyCounts;
    string highestVoteCity = "";
    string highestVoteParty = "";
    double highestVotePercent = 0.0;
    
    for (const auto& pair : cities_data) {
        const CityData& data = pair.second;
        partyCounts[data.winnerParty]++;
        
        for (const auto& vote : data.votes) {
            string pctStr = vote.percentage;
            if (!pctStr.empty() && pctStr[0] == '%') {
                pctStr = pctStr.substr(1);
            }
            try {
                double pct = stod(pctStr);
                if (pct > highestVotePercent) {
                    highestVotePercent = pct;
                    highestVoteCity = data.name;
                    highestVoteParty = vote.name;
                }
            } catch (...) {
            }
        }
    }
    
    cout << "Total Municipalities Won by Parties:\n";
    for (const auto& pair : partyCounts) {
        cout << "  " << pair.first << ": " << pair.second << " municipalities\n";
    }
    
    if (!highestVoteCity.empty()) {
        cout << "\nHighest Vote Percentage in a Single City:\n";
        cout << "  City: " << highestVoteCity << "\n";
        cout << "  Party: " << highestVoteParty << "\n";
        cout << "  Percentage: %" << highestVotePercent << "\n";
    }
}
