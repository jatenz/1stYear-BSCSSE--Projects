#include <iostream>
#include <string>
using namespace std;

struct Product{
    int price;
    string name;
    char type;
};

void print(Product* obj, int size){
    for (int i = 0; i < size; i++){
        cout << "Product " << i + 1 << ": " << endl;
        cout << "\tProduct Name: " << obj[i].name << endl;
        cout << "\tProduct Price: " << obj[i].name << endl;
        cout << "\tProduct Type: " << obj[i].name << endl;
    }
}

int main(){
    Product* newproduct = new Product[10];

    for (int i = 0; i < 5; i++){
        cout << "Product " << i + 1 << ": " << endl;


        Product products;
        cout << "\tProduct Name: ";
        cin >> products.name;
        cout << "\tProduct Price: ";
        cin >> products.price;
        cout << "\tProduct Type: ";
        cin >> products.type;

        newproduct[i] = products;

        system("cls");
    }

    print(newproduct, 5);

    delete[] newproduct;
}