#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

struct Project {
    string id, firstName, middleName, lastName, userName, password, confirmPassword, no;
};

const int MAX_ACCOUNTS = 100;
Project accounts[MAX_ACCOUNTS];
int accountCount = 0;

int option;

void accountMenu();

void accountCAPTCHA();

bool passwordChecker(const string& password);

bool phoneNumChecker(const string& no);

string generateRandomString(int length);

void signIn();

void menu(int index);

void showProfile(int i);

void signUp();

void magicSquare();

void loop();

int main() {
    accountMenu();
    switch (option) {
        case 1:
            signIn();
            loop();
            break;
        case 2:
            signUp();
            loop();
            break;
        case 3:
            break;
    }
    return 0;
}

void accountMenu() {
    cout << "\nACCOUNT MENU" << endl;
    cout << "[1] Sign-in" << endl;
    cout << "[2] Sign-up" << endl;
    cout << "[3] Exit" << endl;
    cout << "\nOption: ";
    cin >> option;
}

void accountCAPTCHA() {
    srand(static_cast<unsigned int>(time(0)));
    string enterRand = generateRandomString(8);
    bool randCheck = false;

    for (int i = 1; i <= 5; ++i) {
        cout << "\nRandom String: " << enterRand << endl;
        string inputRand;
        cout << "Confirm CAPTCHA: ";
        cin >> inputRand;

        if (enterRand == inputRand) {
            randCheck = false;
            break;
        } else {
            cout << "Incorrect CAPTCHA. Try again. Attempts remaining: " << 5 - i << endl;
        }
    }

    if (randCheck) {
        cout << "Too many incorrect attempts. Exiting program." << endl;
        exit(0);
    }
}

bool passwordChecker(const string& password) {
    bool lowerCase = false, upperCase = false, digitChar = false, specialChar = false;

    if (password.length() < 8) {
        cout << "Password must be at least 8 characters in length." << endl;
        return false;
    }

    for (char letter : password) {
        if (isupper(letter)) {
            upperCase = true;
        } else if (islower(letter)) {
            lowerCase = true;
        } else if (isdigit(letter)) {
            digitChar = true;
        } else if (ispunct(letter)) {
            specialChar = true;
        }
    }

    if (!lowerCase) {
        cout << "Password must have at least 1 lowercase alphabet." << endl;
    }
    if (!upperCase) {
        cout << "Password must have at least 1 uppercase alphabet." << endl;
    }
    if (!digitChar) {
        cout << "Password must have at least 1 digit character." << endl;
    }
    if (!specialChar) {
        cout << "Password must have at least 1 special character." << endl;
    }

    return lowerCase && upperCase && digitChar && specialChar;
}

bool phoneNumChecker(const string& no) {
    bool phoneDigit = true;

    if (no.length() != 11) {
        cout << "Mobile Number must be exactly 11 digits in length." << endl;
        return false;
    }

    for (char number : no) {
        if (!isdigit(number)) {
            phoneDigit = false;
            break;
        }
    }

    if (!phoneDigit) {
        cout << "Mobile Number must only have numbers." << endl;
    }

    return phoneDigit;
}

string generateRandomString(int length) {
    const string characters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string randomString;

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        randomString += characters[index];
    }

    return randomString;
}

void signIn() {
    cout << "\nSIGN-IN" << endl;
    int countTries = 5;
    do {
        string inputUser, inputPass;
        cout << "Username: ";
        cin >> inputUser;
        cout << "Password: ";
        cin >> inputPass;

        int index = -1;
        for (int i = 0; i < accountCount; ++i) {
            if (accounts[i].userName == inputUser && accounts[i].password == inputPass) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "\nWelcome, " << accounts[index].firstName << "!\n";
            menu(index);
            break;
        } else {
            cout << "\nIncorrect username or password. Please try again." << endl;
            countTries--;

            if (countTries == 0) {
                cout << "Too many incorrect attempts. Complete the CAPTCHA." << endl;
                accountCAPTCHA();
                countTries = 5;
            } else {
                cout << "Number of Tries remaining: " << countTries << endl;
            }
        }
    } while (true);
}

void menu(int index) {
    cout << "\nMENU" << endl;
    cout << "[1] Show Profile" << endl;
    cout << "[2] Play Game (Magic Square)" << endl;
    cout << "[3] Back" << endl;
    cout << "Option: ";
    cin >> option;

    switch (option) {
        case 1:
            showProfile(index);
            break;
        case 2:
            magicSquare();
            break;
        case 3:
            loop();
            break;
    }
}

void showProfile(int i) {
    cout << "\nID: " << accounts[i].id << endl;
    cout << "Full Name: " << accounts[i].firstName + " " + accounts[i].middleName + " " + accounts[i].lastName << endl;
    cout << "Username: " << accounts[i].userName << endl;
    cout << "Password: " << accounts[i].password << endl;
    cout << "Mobile No. : " << accounts[i].no << endl;
}

void signUp() {
    cout << "\nSIGN-UP" << endl;

    Project newAccount;
    newAccount.id = to_string(accountCount + 1);

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

    newAccount.userName = newAccount.firstName.substr(0, 1) + newAccount.middleName.substr(0, 1) + newAccount.lastName;

    cout << "Username: " << newAccount.userName << endl;

    do {
        cout << "Password: ";
        cin >> newAccount.password;
    } while (!passwordChecker(newAccount.password));

    do {
        cout << "Confirm Password: ";
        cin >> newAccount.confirmPassword;
        if (newAccount.confirmPassword != newAccount.password) {
            cout << "Passwords do not match. Try again." << endl;
        }
    } while (newAccount.confirmPassword != newAccount.password);

    do {
        cout << "Mobile Number: ";
        cin >> newAccount.no;
    } while (!phoneNumChecker(newAccount.no));

    accounts[accountCount++] = newAccount;
    cout << "Account successfully created!\n";
}

void magicSquare() {
    int arr[3][3];
    cout << "\nEnter values for the 3x3 matrix:" << endl;
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> arr[i][j];

    bool magicSquareChecker = true;

    int sum = arr[0][0] + arr[0][1] + arr[0][2]; // Sum of first row

    for (int i = 0; i < 3; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum += arr[i][j];
            colSum += arr[j][i];
        }

        if (rowSum != sum || colSum != sum) {
            magicSquareChecker = false;
            break;
        }
    }

    if (arr[0][0] + arr[1][1] + arr[2][2] != sum || arr[0][2] + arr[1][1] + arr[2][0] != sum) {
        magicSquareChecker = false;
    }

    if (magicSquareChecker) {
        cout << "Congratulations, You have completed the game" << endl;
    } else {
        cout << "The entered values do not form a magic square. Please try again.\n";
        magicSquare();
    }
}

void loop() {
    do {
        accountMenu();
        switch (option) {
            case 1:
                signIn();
                break;
            case 2:
                signUp();
                break;
            case 3:
                break;
        }
    } while (option != 3);
}
