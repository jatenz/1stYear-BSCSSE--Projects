#include<iostream>
#include<string>
using namespace std;

string varName;
int iniVal;
string cond;
int terVal;
string upd;
int option;

void loopMenu(){
    cout << "LOOP SIMULATION" << endl;
    cout << "[1] for loop" << endl;
    cout << "[2] while loop" << endl;
    cout << "[3] do-while loop" << endl;
}

void userInput(){
    cout << "Variable Name: ";
    cin >> varName;
    cout << "Initial Value: ";
    cin >> iniVal;
    cout << "Conditional Operator: ";
    cin >> cond;
    cout << "Terminal Value: ";
    cin >> terVal;
    cout << "Update: ";
    cin >> upd;
}

void forLoop() {
    userInput();

    if ((cond == "<") || (cond == ">") || (cond == "==") || (cond == "!=") || (cond == "<=") || (cond == ">=")) {
        for (int i = iniVal; i < terVal; i++){
            cout << "for (int " << varName << "; " << varName << cond << terVal << "; " << varName << upd << ")";
        }
    } else {
        cout << "Invalid condition" << endl;
    }
}

int main(){
    loopMenu();

    cout << "Option: ";
    cin >> option;
    switch (option){
        case 1:
            forLoop();
            break;
        case 2:
            break;
        case 3:
            break;
    }


}