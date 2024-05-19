#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int clickNumber = 0;

int calculateChanceOfLosing(int clicks) {
    return min(100, clicks);
}

bool checkLose(int chanceOfLosing) {
    int randomNumber = rand() % 100 + 1;
    return randomNumber <= chanceOfLosing;
}

int main() {
    srand(time(0));

    cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
    cout << "\t\t\t\t\t|                   C    L    I    C    K    E    R          G    A    M    E                       |" << endl;
    cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;

    char choice;
    do {
        cout << "\t\t\t\t\t\t\t[Y] - CLICK" << endl;
        cout << "\t\t\t\t\t\t\t[N] - STOP" << endl;
        cout << "\t\t\t\t\t\t\tChoice: ";
        cin >> choice;

        switch (choice) {
            case 'Y':
            case 'y': {
                clickNumber++;
                int chanceOfLosing = calculateChanceOfLosing(clickNumber);
                cout << "\n\t\t\t\t\tNumber of Clicks: " << clickNumber << endl;
                if (checkLose(chanceOfLosing)) {
                    cout << "\t\t\t\t\tYou lose! [Number of Clicks = 0]" << endl;
                    clickNumber = 0;
                }
                break;
            }
            case 'N':
            case 'n':
                break; 
            default:
                cout << "\n\t\t\t\t\t\tINVALID OPTION" << endl;
                break;
        }
    } while (true);

    return 0;
}
