#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//option
int option;

// Function prototypes
void menu(); // Function to display the menu options
void playGuessNumber(); // Function to play the Guess Number game
void playFlames(); // Function to play the FLAMES game
void loop(); // Function to loop through the menu options

// Function to generate a random string of digits
string generateRandomString(int length){
    const string characters = "0123456789";
    string randomString;

    for (int i = 0; i < length; ++i){
        int index = rand() % characters.length();
        randomString += characters[index];
    }

    return randomString;
}

// Main function
int main(){
    loop(); // Start the menu loop
    return 0;
}

// Function to display the menu options
void menu(){
    cout << "__________________________________________________________________" << endl;
    cout << "                               MENU                               " << endl;
    cout << "==================================================================" << endl;
    cout << "\n[1] - Flames Game" << endl;
    cout << "[2] - Guess Number Game" << endl;
    cout << "[3] - Exit" << endl;
    cout << "Select Option: ";
    cin >> option; // Get the user's option
}

// Function to play the Guess Number game
void playGuessNumber(){
    string userInput;
    do{
        srand(static_cast<unsigned int>(time(0)));
        string randomNumber = generateRandomString(1);
        cout << "\n__________________________________________________________________" << endl;
        cout << "                         GUESS NUMBER GAME                        " << endl;
        cout << "==================================================================" << endl;
        cout << "\nEnter Number: ";
        cin >> userInput; // Get user's input
        cout << "Guess Number: " << randomNumber << endl;
        if (userInput == randomNumber){
            cout << "Results: WIN" << endl;
            loop(); // Go back to the main menu
        } else{
            cout << "Results: LOSE" << endl;
        }
    } while(true); // Keep playing until the user exits
}

// Function to play the FLAMES game
void playFlames(){
    string name1, name2;

    cout << "__________________________________________________________________" << endl;
    cout << "                           FLAMES GAME                            " << endl;
    cout << "==================================================================" << endl;

    cout << "\nEnter the first name: ";
    cin.ignore();
    getline(cin, name1); // Get the first name
    cout << "Enter the second name: ";
    getline(cin, name2); // Get the second name

    // Convert names to uppercase for case-insensitive comparison
    transform(name1.begin(), name1.end(), name1.begin(), ::toupper);
    transform(name2.begin(), name2.end(), name2.begin(), ::toupper);

    string flames = "FLAMES";
    int count = 0;

    // Remove common letters
    string tempName1 = name1, tempName2 = name2;
    for (char c : name1){
        size_t found = tempName2.find(c);
        if (found != string::npos){
            tempName1.erase(remove(tempName1.begin(), tempName1.end(), c), tempName1.end());
            tempName2.erase(found, 1);
        }
    }

    // Calculate remaining characters
    string combined = tempName1 + tempName2;
    count = combined.length();

    // Find the FLAMES category
    while (flames.length() > 1){
        int index = (count % flames.length()) - 1;
        if (index < 0){
            index = flames.length() - 1;
        }
        flames.erase(index, 1);
    }

    // Determine the relationship
    char result = flames[0];
    switch (result){
        case 'F':
            cout << "\nRelationship - Friends" << endl;
            break;
        case 'L':
            cout << "\nRelationship - Lovers" << endl;
            break;
        case 'A':
            cout << "\nRelationship - Angry" << endl;
            break;
        case 'M':
            cout << "\nRelationship - Marry" << endl;
            break;
        case 'E':
            cout << "\nRelationship - Enemy" << endl;
            break;
        case 'S':
            cout << "\nRelationship - Sweet" << endl;
            break;
        default:
            cout << "\nError: Invalid result" << endl;
            break;
    }
}

// Function to loop through the menu options
void loop(){
    menu(); // Display the menu
    switch (option){
        case 1:
            system("cls");
            playFlames(); // Play the FLAMES game
            loop();
            break;
        case 2:
            system("cls");
            playGuessNumber(); // Play the Guess Number game
            break;
        case 3:
            break; // Exit the program
    }
}
