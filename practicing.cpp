#include <iostream>
using namespace std;


int main(){
    int inputNumber, even_odd;
    
    cout << "******************************************************************************************" << endl;
    cout << "                         E  V  E  N     O  R    O  D  D" << endl;
    cout << "******************************************************************************************" << endl;
    
    while(true){
        cout << "\tPlease Enter any Number: ";
        cin >>  inputNumber;
         
        even_odd = inputNumber % 2;
        if (even_odd == 0){
            cout << "\t\tThe number " << inputNumber << " is even" << endl;
        }else
             cout << "\t\tThe number " << inputNumber << " is odd" << endl;
    }
    
    return 0;
}
