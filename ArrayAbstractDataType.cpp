#include <iostream>
using namespace std;

class Array1D {
private:
    int capacity;
    int size;
    int *arr;

public:
    Array1D(int ArrayCapacity = 10);
    ~Array1D() {
        delete[] arr;
    }
    int GetSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void InsertItem(int pos, int val) {
        if (pos < 0 || pos > size || isFull()) {
            cout << "Invalid position or array is full." << endl;
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        size++;
    }

    void RemoveItem(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position." << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void AddItem(int val) {
        if (isFull()) {
            cout << "Array is full." << endl;
            return;
        }
        arr[size++] = val;
    }

    void DisplayElements() const {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

Array1D::Array1D(int ArrayCapacity) {
    capacity = ArrayCapacity;
    size = 0;
    arr = new int[capacity];
}

int main() {
    Array1D arr(5);
    arr.AddItem(10);
    arr.AddItem(20);
    arr.AddItem(30);
    arr.DisplayElements();
    arr.InsertItem(1, 15);
    arr.DisplayElements();
    arr.AddItem(40);
    arr.DisplayElements();
    arr.AddItem(50);
    arr.RemoveItem(0);
    arr.DisplayElements();
    cout << "Array size: " << arr.GetSize() << endl;
    if (arr.isEmpty()) {
        cout << "Array is empty!" << endl;
    }
    else {
        cout << "Array is not empty!" << endl;
    }
    return 0;
}
