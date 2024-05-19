#include <iostream>
using namespace std;

int arrNum[10] = {};
int loop;

void instructions(){
    cout << "\nACTIVITY 2.1: Even and Its Position\n" << endl;
    cout << "***************************************************************************************" << endl;
    cout << "This program will identify the position of all even numbers in an array of 10 elements." << endl;
    cout << "***************************************************************************************" << endl;
}

int main(){
    instructions();
    do{
        cout << "\n";
        cout << "\nEnter 10 numbers: ";
        for (int i = 1; i < 11; i++){
            cin >> arrNum[i];
        }
        cout << "Even numbers are located at indices: ";
        for (int i = 1; i < 11; i++){
            if (arrNum[i] % 2 == 0){
                cout << i << " ";
            }
        }
    loop++;
    }while(loop != 2);

    return 0;
}