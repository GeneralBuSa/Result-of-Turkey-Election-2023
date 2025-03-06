#include "Election.h"
#include "Mayority.h"
#include "WinnerParty.h"
#include "Percentage.h"
#include "Cities.h"
#include <fstream>
using namespace std;

int main() {

    ofstream clearFile("election.txt", ios::trunc);
    clearFile.close();
    Election E1;
    Mayority M1;
    Percentage P1;
    WinnerParty W1;
    
    ofstream logFile("election.txt", ios::app);
    if (!logFile) {
        cerr << "Error opening log file!" << endl;
        return 1;
    }
    
    int plaque, choice;
    while (true) {
        choice = E1.whatDoYouWant();
        logFile << "User choice: " << choice << endl;
        
        while (E1.checkWhatDoYouWant(choice) == 0) {
            cout << "Please enter a valid number (1-4)" << endl;
            cin >> choice;
            logFile << "Invalid choice. User re-entered: " << choice << endl;
        }
        
        if (choice == 4) break;
        
        cout << "Please enter the plaque: " << endl;
        cin >> plaque;
        logFile << "User plaque: " << plaque << endl;
        
        while (E1.checkPlaqueNumber(plaque) == 0) {
            cout << "Please enter a valid number (1-81)" << endl;
            cin >> plaque;
            logFile << "Invalid plaque. User re-entered: " << plaque << endl;
        }
        
        switch (choice) {
            case 1:
                M1.setPlaque(plaque);
                M1.Mayor();
                logFile << "Mayor search performed for plaque: " << plaque << endl;
                break;
            case 2:
                W1.setPlaque(plaque);
                W1.Party();
                logFile << "Winner party search performed for plaque: " << plaque << endl;
                break;
            case 3:
                P1.setPlaque(plaque);
                P1.percentage();
                logFile << "Percentage calculation performed for plaque: " << plaque << endl;
                break;
        }
        
        cout << "\nWould you like to perform another search? (yes=1 / no=0): ";
        int repeat;
        cin >> repeat;
        logFile << "User choice for another search: " << repeat << endl;
        if (repeat == 0) break;
    }
    
    logFile << "Program ended." << endl;
    logFile.close();
    
    cout << "Thank you for using our program!" << endl;
    return 0;
}
