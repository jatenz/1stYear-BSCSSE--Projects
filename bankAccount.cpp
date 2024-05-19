#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

int userInput;
void displayMenu();
void login();
void registration();
void forgot();

int main(){
    
    while(true){
        displayMenu();
        switch(userInput){
            case 1:
                system("cls");
                cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
                cout << "\t\t\t\t\t|                                       L    O    G    I    N                                       |" << endl;
                cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;
                login();
                break;
            case 2:
                system("cls");
                cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
                cout << "\t\t\t\t\t|                     R    E    G    I    S    T    R    A    T    I    O    N                      |" << endl;
                cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;
                registration();
                break;
            case 3:
                break;
            case 4:
                system("cls");
                cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
                cout << "\t\t\t\t\t|           R    E    C    O    V    E    R         P    A    S    S    W    O    R    D            |" << endl;
                cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;
                forgot();
                break;
            case 5:
                cout << "\t\t\t\t\tExiting Program...";
                cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
                cout << "\t\t\t\t\t|                 P    R    O    G    R    A    M          E    X    I    T    E    D               |" << endl;
                cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;                
                return 0;
            default:
                cin.clear();
                while (cin.get() != '\n'); 
                system("cls");
                cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
                cout << "\t\t\t\t\t|                  I   N    V    A    L    I   D          O    P    T    I    O    N                |" << endl;
                cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;
                cout << "\t\t\t\t\t\t\tPlease Input [1] - [2] - [3] - [4] - [5] Only" << endl;
                break;
        }
    }
    return 0;
}

void displayMenu(){
    cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
    cout << "\t\t\t\t\t|      W   E   L   C   O   M   E          T    O          T    H    E          M    E    N   U      |" << endl;
    cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;
    cout << "\t\t\t\t\t\t\t| [1] - LOGIN                          |" << endl;
    cout << "\t\t\t\t\t\t\t| [2] - REGISTER                       |"<< endl;
    cout << "\t\t\t\t\t\t\t| [3] - VIEW PROFILE                   |" << endl;
    cout << "\t\t\t\t\t\t\t| [4] - FORGOT PASSWORD / USERNAME     |" << endl;
    cout << "\t\t\t\t\t\t\t| [5] - EXIT                           |" << endl;
    cout << "\t\t\t\t\tOption: ";
    cin >> userInput;
}

void login(){
    int count;
    string userName, userPassword, inputName, inputPassword;

    cout << "\t\t\t\t\tPlease Enter the Following Details: " << endl;
    cout << "\n\t\t\t\t\t\t\t| Username: ";
    cin >> inputName;
    cout << "\t\t\t\t\t\t\t| Password: ";
    cin >> inputPassword;

    ifstream loginFile("database.txt");
    while(loginFile >> userName >> userPassword){
        if (inputName == userName && inputPassword == userPassword){
            count = 1;
            system("cls");
            cout << "\n\t\t\t\t\tVerifying Username & Password...";
            cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
            cout << "\t\t\t\t\t|            L    O    G    I    N          S    U    C    C    E    S    S    F    U    L          |" << endl;
            cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;      
            cout << "\t\t\t\t\t\t\tWelcome, " << userName;
            break; // Exit the loop after successful login
        }
    }
    loginFile.close();

    if (count != 1){
        cout << "\n\t\t\t\t\tVerifying Username & Password...";
        cout << "\n\t\t\t\t\t|***************************************************************************************************|" << endl;
        cout << "\t\t\t\t\t|                       L    O    G    I    N          E    R    R    O    R                        |" << endl;
        cout << "\t\t\t\t\t|___________________________________________________________________________________________________|" << endl;  
        cout << "\t\t\t\t\tPlease Check your Username and Password." << endl;
    }
}

void registration(){
    string regUserName, regUserPassword, regInputName, regInputPassword;

    cout << "\t\t\t\t\tEnter Username: ";
    cin >> regUserName;
    cout << "\t\t\t\t\tEnter Password: ";
    cin >> regUserPassword;

    ofstream registrationFile("database.txt", ios::app);
    registrationFile << regUserName << " " << regUserPassword << endl;

    cout << "\n\t\t\t\t\tRegistering Account..." << endl;
    cout << "\n\t\t\t\t|******************************************************************************************************************|" << endl;
    cout << "\t\t\t\t| R    E    G    I    S    T    R    A    T    I    O    N          S    U    C    C    E    S    S    F    U    L |" << endl;
    cout << "\t\t\t\t|__________________________________________________________________________________________________________________|" << endl;            

}

void forgot(){
    int option;
    cout << "\t\t\t\t\tForgotten? We're here to help." << endl;
    cout << "\t\t\t\t\t\t\t| [1] - SEARCH YOUR ID BY USERNAME     |" << endl;
    cout << "\t\t\t\t\t\t\t| [2] - RETURN                         |"<< endl;
    cout << "\t\t\t\t\tOption: ";
    cin >> option;

    switch(option){
        case 1:
            int count = 0;
            string searchUser, inputSearchUser, inputSearchPassword;
            cout << "\n\t\t\t\t\tEnter your remembered username: ";
            cin >> searchUser;

            ifstream searchFile("database.txt");
            while(searchFile >> inputSearchUser >> inputSearchPassword){
                if(searchUser == inputSearchUser){
                    count = 1;
                }
            }
            searchFile.close();
            if(count == 1){
                cout << "\n\t\t\t\t\tAccount Found." << endl;
                cout << "\t\t\t\t\tYour Password is: " << inputSearchPassword;
                cin.get();
            }else{
                cout << "\n\t\t\t\t\tSorry, Your UserID is not found in our Database." << endl;
                cin.get();
            }
            break;
    }
}