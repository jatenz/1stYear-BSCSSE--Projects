#ifndef DATA_H
#define DATA_H

template <typename T>
class Stack {
private:
    T* a;
    int n;
    int top;
public:
    Stack(int size);
    void push(T element);
    T pop();
    void display();
    void operations();
};

#endif