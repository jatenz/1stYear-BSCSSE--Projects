#include <iostream>

using namespace std;

int arr[3][3] = {};
bool magicSquareChecker = false;

void magicSquare() {
    bool leftRight1 = false, leftRight2 = false, leftRight3 = false;
    bool topBot1 = false, topBot2 = false, topBot3 = false;
    bool diagonal1 = false, diagonal2 = false;

    cout << "\n";
    for (int i = 0; i < 3; ++i){
        cout << "Enter #: ";
        for (int j = 0; j < 3; ++j){
            cin >> arr[i][j];
        }
    }

    if ((arr[0][0] + arr[0][1] + arr[0][2]) == 15){
        leftRight1 = true;
    }
    if ((arr[1][0] + arr[1][1] + arr[1][2]) == 15){
        leftRight2 = true;
    }
    if ((arr[2][0] + arr[2][1] + arr[2][2]) == 15){
        leftRight3 = true;
    }
    if ((arr[0][0] + arr[1][0] + arr[2][0]) == 15){
        topBot1 = true;
    }
    if ((arr[0][1] + arr[1][1] + arr[2][1]) == 15){
        topBot2 = true;
    }
    if ((arr[0][2] + arr[1][2] + arr[2][2]) == 15){
        topBot3 = true;
    }
    if ((arr[0][0] + arr[1][1] + arr[2][2]) == 15){
        diagonal1 = true;
    }
    if ((arr[0][2] + arr[1][1] + arr[2][0]) == 15){
        diagonal2 = true;
    }

    if (leftRight1 && leftRight2 && leftRight3 && topBot1 && topBot2 && topBot3 && diagonal1 && diagonal2){
        magicSquareChecker = true;
    } else {
        cout << "The entered values do not form a magic square. Please try again.\n";
    }
}

int main() {
    do {
        magicSquare();
    } while (!magicSquareChecker);

    cout << "Congratulations, You have completed the game" << endl;

    return 0;
}
