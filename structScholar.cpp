#include <iostream>

using namespace std;

struct Scholar {
    int id;
    char name[50];
    double gwa1;
    double gwa2;
    double gwa3;
    double total_gwa;
};

int main() {
    Scholar scholars[3];

    cout << "Scholar Records" << endl;
    for (int i = 0; i < 3; i++){
        cout << endl << "Student ID: ";
        cin >> scholars[i].id;
        cin.ignore();
        cout << "Name: ";
        cin.getline(scholars[i].name, 50);
        cout << "GWA 1: ";
        cin >> scholars[i].gwa1;
        cout << "GWA 2: ";
        cin >> scholars[i].gwa2;
        cout << "GWA 3: ";
        cin >> scholars[i].gwa3;

        scholars[i].total_gwa = (scholars[i].gwa1 + scholars[i].gwa2 + scholars[i].gwa3) / 3;
    }

    cout << "Summary of Report" << endl;
    cout << "Scholar Records" << endl;
    for (int i = 0; i < 3; i++){
        cout << endl << "Scholar ID: " << scholars[i].id;
        cout << endl << "Name: " << scholars[i].name;
        cout << endl << "GWA 1: " << scholars[i].gwa1;
        cout << endl << "GWA 2: " << scholars[i].gwa2;
        cout << endl << "GWA 3: " << scholars[i].gwa3;
        cout << endl << "Total GWA: " << scholars[i].total_gwa;
    }

    return 0;
}
