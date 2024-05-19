#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string str1;
string str2;

int main(){
    cout << "\nEnter a first word (str1): ";
    cin >> str1;
    cout << "Enter a second word (str2): ";
    cin >> str2;

    if (str1 == str2){
        cout << "\nEqual" << endl;
    }else{
        cout << "\nNot Equal\n" << endl;
    }
    return 0;
}