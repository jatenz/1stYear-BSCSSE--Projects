#include <iostream>
#include <string>

using namespace std;

string word;
int option = 0;

void newtext() {
    cout << "\n";
    cout << "\nEnter a word to decipher: ";
    cin >> word;
    cout << "Original String " << word << endl;
    cout << "Deciphered String: ";
    for (char letter : word) {
        if (islower(letter)) {
            if (letter == 'a') {
                cout << 'z';
            } else {
                letter--;
                cout << letter;
            }
        } else if (isupper(letter)) {
            if (letter == 'A') {
                cout << 'Z';
            } else {
                letter--;
                cout << letter;
            }
        } else {
            cout << letter;
        }
    }
}

void oldtext() {
    cout << "\n";
    cout << "\nEnter a word to encrypt: ";
    cin >> word;
    cout << "Original String " << word << endl;
    cout << "Encrypted String: ";
    for (char letter : word) {
        if (islower(letter)) {
            if (letter == 'z') {
                cout << 'a';
            } else {
                letter++;
                cout << letter;
            }
        } else if (isupper(letter)) {
            if (letter == 'Z') {
                cout << 'A';
            } else {
                letter++;
                cout << letter;
            }
        } else {
            cout << letter;
        }
    }
}

void loop() {
    cout << "\n[1] - Encrypt " << endl;
    cout << "[2] - Decipher " << endl;
    cout << "[3] - Exit " << endl;
    cout << "\nSelect Option: ";
    cin >> option;
    switch (option) {
        case 1:
            oldtext();
            cout << "\n";
            loop();
            break;
        case 2:
            newtext();
            cout << "\n";
            loop();
            break;
        case 3:
            break;
        default:
            cout << "Please Enter [1], [2], or [3] only\n";
            break;
    }
}

int main() {
    cout << "\n[1] - Encrypt " << endl;
    cout << "[2] - Decipher " << endl;
    cout << "[3] - Exit " << endl;
    cout << "\nSelect Option: ";
    cin >> option;
    switch (option) {
        case 1:
            oldtext();
            cout << "\n";
            loop();
            break;
        case 2:
            newtext();
            cout << "\n";
            loop();
            break;
        case 3:
            break;
        default:
            cout << "Please Enter [1], [2], or [3] only\n";
            break;
    }
    return 0;
}
