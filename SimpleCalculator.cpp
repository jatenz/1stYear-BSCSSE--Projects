#include<iostream>
using namespace std;

int firstNum, secNum, choice;

//adding the num
void addNum(){
    int sum;
    sum = firstNum + secNum;
    cout << "\nResult: " << sum << endl;
}
//subtracting the num
void subNum(){
    int dif;
    dif = firstNum - secNum;
    cout << "\nResult: " << dif << endl;
}
//multiplying the num
void mulNum(){
    int prod;
    prod = firstNum * secNum;
    cout << "\nResult: " << prod << endl;
}
//dividing the num
void divNum(){
    int quo;
    quo = firstNum / secNum;
    cout << "\nResult: " << quo << endl;
}
//modulo of num
void modNum(){
    int mods;
    mods = firstNum % secNum;
    cout << "\nResult: " << mods << endl;
}
//prints the instructions
void menu(){
    cout << "------------------------------------------------------" << endl;
    cout << "                         MENU                         " << endl;
    cout << "======================================================" << endl;
    cout << "\t 1. Add" << endl;
    cout << "\t 2. Subtract" << endl;
    cout << "\t 3. Multiply" << endl;
    cout << "\t 4. Divide" << endl;
    cout << "\t 5. Modulus" << endl;
}
//gets the user input
void opt(){
    cout << "Enter your choices(1-5): ";
    cin >> choice;
}
//conditional loop
void cont(){
    char loop;
    cout << "Press y or Y to continue: ";
    cin >> loop; //gets the user input
        if (loop == 'y' || loop == 'Y'){ //if true create a loop
            menu();
            opt();

            switch (choice){
                case 1:
                    cout << "Enter your two integer numbers: ";
                    cin >> firstNum >> secNum;
                    addNum();
                    break;
                case 2:
                    cout << "Enter your two integer numbers: ";
                    cin >> firstNum >> secNum;
                    subNum();
                    break;
                case 3:
                    cout << "Enter your two integer numbers: ";
                    cin >> firstNum >> secNum;
                    mulNum();
                    break;
                case 4:
                    cout << "Enter your two integer numbers: ";
                    cin >> firstNum >> secNum;
                    divNum();
                    break;
                case 5:
                    cout << "Enter your two integer numbers: ";
                    cin >> firstNum >> secNum;
                    modNum();
                    break;
                }
            cont(); 
        }
}
int main(){
    menu(); //prints the menu
    opt(); //gets user input

    switch (choice){
        case 1: //addition
            cout << "Enter your two integer numbers: ";
            cin >> firstNum >> secNum;
            addNum(); //prints the sum
            break;
        case 2: //subtraction
            cout << "Enter your two integer numbers: ";
            cin >> firstNum >> secNum;
            subNum(); // prints the difference
            break;
        case 3: //multiplication
            cout << "Enter your two integer numbers: ";
            cin >> firstNum >> secNum;
            mulNum(); //prints the product
            break;
        case 4: // divition
            cout << "Enter your two integer numbers: ";
            cin >> firstNum >> secNum;
            divNum(); // prints the quotient
            break;
        case 5: //modulo
            cout << "Enter your two integer numbers: ";
            cin >> firstNum >> secNum;
            modNum(); // prints the modulo
            break;
    }
    cont(); //continues to loop the program
    return 0;
}