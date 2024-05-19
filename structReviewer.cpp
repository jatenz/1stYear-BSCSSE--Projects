#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Define the structure for the Project
struct Project {
    string id;
    string firstName;
    string middleName;
    string lastName;
    string username;
    string password;
    string mobileNo;
};

// Declare constants and variables
const int maxAccounts = 10;
Project accounts[maxAccounts];
int accountCount = 0;

// Declare global variables for username and password input
string usernameInput, passwordInput;

// Function prototypes
void accountSignUp();
void accountShowProfile(int i);
bool passwordChecker(const string& password);
void accountSignIn(int i);
void loop();

// Main function
int main() {
    int i = 0;
    accountSignUp();
    accountSignIn(i);
    return 0;
}

// Function to check if a password meets specified criteria
bool passwordChecker(const string& password) {
    bool lowerCase = false;
    bool upperCase = false;
    bool numbers = false;
    bool special = false;

    // Check if the password length is at least 8 characters
    if (password.length() < 8) {
        return false;
    }

    // Check each character of the password for specific criteria
    for (char letter : password) {
        if (islower(letter)) {
            lowerCase = true;
        } else if (isupper(letter)) {
            upperCase = true;
        } else if (isdigit(letter)) {
            numbers = true;
        } else if (ispunct(letter)) {
            special = true;
        }
    }

    // Return true if all criteria are met
    return lowerCase && upperCase && numbers && special;
}

// Function for user account sign-up
void accountSignUp() {
    cout << "\nSIGN UP\n";

    Project newAccount;

    // Input user details
    cout << "ID: ";
    cin >> newAccount.id;

    cout << "First Name: ";
    cin >> newAccount.firstName;
    for (char& letter : newAccount.firstName) {
        letter = tolower(letter);
    }

    cout << "Middle Name: ";
    cin >> newAccount.middleName;
    for (char& letter : newAccount.middleName) {
        letter = tolower(letter);
    }

    cout << "Last Name: ";
    cin >> newAccount.lastName;
    for (char& letter : newAccount.lastName) {
        letter = tolower(letter);
    }

    // Generate username
    newAccount.username = newAccount.firstName.substr(0, 1) + newAccount.middleName.substr(0, 1) + newAccount.lastName;
    cout << "Username: " << newAccount.username << endl;

    // Input and validate password
    do {
        cout << "Password: ";
        cin >> newAccount.password;
    } while (!passwordChecker(newAccount.password));

    // Input mobile number
    cout << "Mobile Number: ";
    cin >> newAccount.mobileNo;

    // Add the new account to the array
    accounts[accountCount++] = newAccount;
}

// Function to display user profile
void accountShowProfile(int i) {
    if (i >= 0 && i < accountCount) {
        cout << "\nID: " << accounts[i].id << endl;
        cout << "First Name: " << accounts[i].firstName << endl;
        cout << "Middle Name: " << accounts[i].middleName << endl;
        cout << "Last Name: " << accounts[i].lastName << endl;
        cout << "Username: " << accounts[i].username << endl;
        cout << "Password: " << accounts[i].password << endl;
        cout << "Mobile Number: " << accounts[i].mobileNo << endl;
    } else {
        cout << "Invalid index. No profile to show." << endl;
    }
}

// Function for user account sign-in
void accountSignIn(int i) {
    cout << "\nEnter Username: ";
    cin >> usernameInput;
    cout << "Enter Password: ";
    cin >> passwordInput;

    // Check if the entered username and password match
    if (accounts[i].username == usernameInput && accounts[i].password == passwordInput) {
        cout << "Login Successfully\n" << "Welcome, " << accounts[i].firstName << endl;
        accountShowProfile(i);
        loop();
    } else {
        cout << "Invalid Username and Password. No profile to show." << endl;
    }
}

void loop() {
    for (int i = 0; i < accountCount; ++i) {
        accountSignUp();
        accountSignIn(accountCount - 1); // Sign in with the newly created account
    }
}