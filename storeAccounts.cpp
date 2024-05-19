#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Project{
    string name;
    int age;
};

string inputName;
int inputAge;

const int maxNum = 10;
Project newAccounts[maxNum];
int counter;

void SignIn();
void SignUp();
void loop();

int main(){
    SignUp();
    SignIn();
    loop();

    return 0;
}

void SignIn(){
    Project account;

    cout << "Name: ";
    cin >> inputName;
    cout << "Age: ";
    cin >> inputAge;

    int index = -1;

    if (account.name == inputName && account.age == inputAge){
        cout << "Welcome " << account.name;
        index++;

    }else{
        cout << "Wrong Name or Age";
    }

}

void SignUp(){
    Project account;

    cout << "Enter Name: ";
    cin >> account.name;
    cout << "Enter Age: ";
    cin >> account.age;

    counter++;
}

void loop(){
    SignIn();
    SignUp();
    loop();
}