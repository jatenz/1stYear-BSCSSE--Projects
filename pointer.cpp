#include <iostream>
#include <string>
using namespace std;


int main(){
    int studentID;
    string name;
    string course;
    string yearLevel;

    int *ptrstudentID = &studentID;
    string *ptrname = &name;
    string *ptrcourse = &course;
    string *ptryearLevel = &yearLevel;

    cout << "\nStudent ID: ";
    cin >> *ptrstudentID;
    cout << "Name: ";
    cin.ignore();
    getline(cin, *ptrname);
    cout << "Course: ";
    getline(cin, *ptrcourse);
    cout << "Year Level: ";
    getline(cin, *ptryearLevel);

    cout << "\nFEU Institute of Technology" << endl;
    cout << "Student Record Management System" << endl;
    cout << "\nStudent ID: " << *ptrstudentID << endl;
    cout << "Name: " << *ptrname << endl;;
    cout << "Course: " << *ptrcourse << endl;
    cout << "Year Level: " << *ptryearLevel << endl;

    return 0;
}