#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateRandomString(int length) {
    const string characters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string randomString;

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        randomString += characters[index];
    }

    return randomString;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Example usage
    string captcha = generateRandomString(8);
    cout << "CAPTCHA: " << captcha << endl;

    return 0;
}