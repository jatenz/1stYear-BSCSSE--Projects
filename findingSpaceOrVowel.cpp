#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

string userInput;
int A, E, I, O, U, space;
int countA, countE, countI, countO, countU, countSpace;

int main(){
    cout << "\nEnter a string: ";
    getline(cin, userInput);

    for (char letter : userInput){
        if (letter == 'A'){
            A++;
        }else if (letter == 'E'){
            E++;
        }else if (letter == 'I'){
            I++;
        }else if (letter == 'O'){
            O++;
        }else if (letter == 'U'){
            U++;
        }else if (isspace(letter)){
            space++;
        }
    }
    for (int i = 1; i <= A; i++){
        countA++;
    }
    for (int i = 1; i <= E; i++){
        countE++;
    }
    for (int i = 1; i <= I; i++){
        countI++;
    }
    for (int i = 1; i <= O; i++){
        countO++;
    }
    for (int i = 1; i <= U; i++){
        countU++;
    }
    for (int i = 1; i <= space; i++){
        countSpace++;
    }
    cout << "\nVowels: " << endl;
    cout << "A = " << countA << endl;
    cout << "E = " << countE << endl;
    cout << "I = " << countI << endl;
    cout << "O = " << countO << endl;
    cout << "U = " << countU << endl;
    cout << "\nWhitespaces - " << countSpace << endl;

    return 0;
}