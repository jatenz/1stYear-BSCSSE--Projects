#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

string str1;
string str2;

int main(){
    cout << "\nEnter a first word (str1): ";
    getline(cin, str1);
    cout << "Enter a second word (str2): ";
    getline(cin, str2);

    str1 = str2;
    cout << "New string value for str1: " << str1;

    return 0;
}