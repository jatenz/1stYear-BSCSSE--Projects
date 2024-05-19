#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

const int week = 7;

struct WeeklyTemperature{
    string city;
    double temp;
};

int main(){
    WeeklyTemperature x[week];
    double averageTemp = 0.0;

    cout << "\nEnter City: ";
    getline(cin, x[0].city);

    cout << "\nEnter temperature for Monday to Sunday" << endl;
    for (int i = 0; i < week; i++) {
        cout << "Temperature Day [" << i + 1 <<  "]: ";
        cin >> x[i].temp;
        averageTemp += x[i].temp;
    }
    averageTemp /= week;
    cout << "Average temperature in " << x[0].city << " is " << setprecision(4) << averageTemp;
    return 0;
}