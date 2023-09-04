#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int totalPlays;
    cout << "Enter the number of times you want to play the Monty Hall game: ";
    cin >> totalPlays;

    int switchWins = 0;
    int stayWins = 0;

    for (int i = 0; i < totalPlays; i++) {
        int prizeLocation = rand() % 3;

        int initialChoice;
        cout << "Choose the door (0, 1, or 2): ";
        cin >> initialChoice;

        int revealedDoor = (prizeLocation == initialChoice) ? (3 - initialChoice - rand() % 2) : (3 - initialChoice - prizeLocation);
        cout << "Monty Oppens " << revealedDoor << " to reveal a goat." << endl;

        int switchChoice;
        cout << "Do you want to switch doors? (1 for yes, 0 for no): ";
        cin >> switchChoice;

        if ((switchChoice == 1 && initialChoice != prizeLocation) || (switchChoice == 0 && initialChoice == prizeLocation)) {
            cout << "Congratulations! You won the prize!" << endl;
            if (switchChoice == 1) {
                switchWins++;
            }
            else {
                stayWins++;
            }
        }
        else {
            cout << "Sorry, you did not win the prize." << endl;
        }
    }
    int totalWins = switchWins + stayWins;
    cout << "Percentage Win : " << static_cast<double>(totalWins) / static_cast<double>(totalPlays) * 100 << " %" << endl;

    return 0;
}
