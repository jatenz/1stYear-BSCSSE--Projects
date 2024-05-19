#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class Bank {
private:
    int pin;
    float balance;
    string id, pass, name, fname, address, phoneNumber;

public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
};

void Bank::menu() {
    system("cls");
    int choice;
    string pin, pass, email;
    cout << "\n\n\t\t\tControl Panel" << endl;
    cout << "1. Bank Management" << endl;
    cout << "2. ATM Management" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your Choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            system("cls");
            cout << "\n\n\t\t\tLogin Account" << endl;
            cout << "E-mail: ";
            cin >> email;
            cout << "Pin Code: ";
            for (int i = 1; i <= 6; i++) {
                char ch = getch();
                pin += ch;
                cout << "*";
            }
            cout << "\nPassword: ";
            for (int i = 1; i <= 7; i++) {
                char ch = getch();
                pass += ch;
                cout << "*";
            }
            if (email == "ijrobledo@gmail.com" && pin == "102329" && pass == "justine") {
                bank_management();
            } else {
                cout << "\nYour E-mail | Pin | Password is Wrong..." << endl;
            }
            break;
        case 2:
            atm_management();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid Value... Please Try Again" << endl;
    }
}

void Bank::bank_management() {
    system("cls");
    int choice;
    cout << "\n\n\t\t\tATM Management System" << endl;
    cout << "1. New User" << endl;
    cout << "2. Already User" << endl;
    cout << "3. Deposit Option" << endl;
    cout << "4. Withdraw Option" << endl;
    cout << "5. Transfer Option" << endl;
    cout << "6. Payment Option" << endl;
    cout << "7. Search User Record" << endl;
    cout << "8. Edit User Record" << endl;
    cout << "9. Delete User Record" << endl;
    cout << "10. Show All Record" << endl;
    cout << "11. Payment All Record" << endl;
    cout << "12. Go Back" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            new_user();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            menu();
            break;
        default:
            cout << "Invalid Value... Please Try Again" << endl;
    }
}

void Bank::atm_management() {
    system("cls");
    int choice;
    cout << "\n\n\t\t\tATM Management System" << endl;
    cout << "1. User Login & Check Balance" << endl;
    cout << "2. Withdraw Amount" << endl;
    cout << "3. Account Details" << endl;
    cout << "4. Go Back" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            new_user();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid Value... Please Try Again" << endl;
    }
}

void Bank::new_user() {
    system("cls");
    fstream file;
    string id, name, fname, address, pin, pass, phone;
    float balance;
    cout << "\n\n\t\t\tAdd New User" << endl;
    cout << "User ID: ";
    cin >> id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Father Name: ";
    getline(cin, fname);
    cout << "Address: ";
    getline(cin, address);
    cout << "Pin Code: ";
    cin >> pin;
    cout << "Password: ";
    cin >> pass;
    cout << "Phone No.: ";
    cin >> phone;
    cout << "Current Balance: ";
    cin >> balance;

    file.open("bank.txt", ios::in);
    if (!file) {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance;
        file.close();
    } else {
        bool found = false;
        string existingId;
        while (file >> existingId) {
            if (existingId == id) {
                found = true;
                break;
            }
        }
        file.close();
        if (found) {
            cout << "\n\n User ID Already Exists..." << endl;
        } else {
            file.open("bank.txt", ios::app | ios::out);
            file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance;
            file.close();
            cout << "\n\n New User Account Created Successfully..." << endl;
        }
    }
}

int main() {
    Bank obj;
    obj.menu();
    return 0;
}
