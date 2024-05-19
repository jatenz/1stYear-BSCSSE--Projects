#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//computation of square
void areaS(int &side, int sq){
    cout << "******************************************************" << endl;
    cout << "                    AREA OF SQUARE                    " << endl;
    cout << "******************************************************" << endl;
    cout << "Enter the side of the square: ";
    cin >> side; //inputs integers
    sq = side * side; //formula for the area of Square
    cout << "The area is " << sq << " sq. units" << endl;
}
//computation of rectangle
void areaR(int &length, int &width, int rc){
    cout << "******************************************************" << endl;
    cout << "                  AREA OF RECTANGLE                   " << endl;
    cout << "******************************************************" << endl;
    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width; //inputs integer
    rc = length * width; // formula for the area of rectangle
    cout << "The area is " << rc << " sq. units" << endl;
}
//computation for triangle
void areaT(int &base, int &height,int tr){
    cout << "******************************************************" << endl;
    cout << "                   AREA OF TRIANGLE                   " << endl;
    cout << "******************************************************" << endl;
    cout << "Enter the base and width of the height: ";
    cin >> base >> height; //inputs integers
    tr = (base * height) / 2; //formula for the area of triangle
    cout << "The area is " << tr << " sq. units" << endl;
}
//computation for circle
void areaC(float &radius, float ci){
    cout << "******************************************************" << endl;
    cout << "                    AREA OF CIRCLE                    " << endl;
    cout << "******************************************************" << endl;
    cout << "Enter the radius: ";
    cin >> radius; //inputs integer
    ci = M_PI * (radius * radius); //formula for the area of circle
    cout << fixed << setprecision(2) << "The area is " << ci << " sq. units" << endl;
}
//the menu
void menu(){
    cout << "------------------------------------------------------" << endl;
    cout << "                         MENU                         " << endl;
    cout << "======================================================" << endl;
    cout << "[1] - Area of square" << endl;
    cout << "[2] - Area of rectangle" << endl;
    cout << "[3] - Area of triangle" << endl;
    cout << "[4] - Area of circle" << endl; 
    cout << "[5] - exit" << endl;   
}
//conditional loop
void loop(int side, int sq, int length, int width, int rc, int base, int height, int tr, float radius, float ci, int opt){
    char key;
    cout << "Thank you!" << endl;
    cout << "Press any key to continue . . . ";  
    cin >> key;
        if (key == 0){
        }else{
            menu();

            cout << "\nEnter your choice: ";
            cin >> opt;
            switch (opt){
            case 1:
                areaS(side, sq);
                break;
            case 2:
                areaR(length, width, rc);
                break;
            case 3:
                areaT(base, height, tr);
                break;
            case 4:
                areaC(radius, ci);
                break;
            case 5:
                loop(side, sq, length, width,rc, base, height, tr, radius, ci, opt);
                break;
            default:
                break;
            }
        }
}
int main(){
    int opt, side, sq, length, width, rc, base, height, tr;
    float radius, ci;
    menu(); //prints the menu

    cout << "\nEnter your choice: "; 
    cin >> opt; //gets user input from 1-5
    switch (opt){
    case 1:
        areaS(side, sq); //the formula for square
        break;
    case 2:
        areaR(length, width, rc); //the formula for rectangle
        break;
    case 3:
        areaT(base, height, tr); //the formula for triangle
        break;
    case 4:
        areaC(radius, ci); //the formula for circle
        break;
    case 5:
        loop(side, sq, length, width,rc, base, height, tr, radius, ci, opt); //conditional loop
        break;
    default:
        break;
    }
    return 0;
}