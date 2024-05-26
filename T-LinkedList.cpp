#include <iostream>
using namespace std;

class Project{
private:
    struct Node{
        int value;
        struct Node* next;
    };
    Node* head;
    Node* back;
public:
    Project(){
        head = nullptr; 
        back = nullptr;   
    }
    ~Project(){
    };
    void insertNode(int num){
        Node* newNode, *nodePtr;

        newNode = new Node;
        newNode->value = num;
        newNode->next = nullptr;

        if (!head){
            head = newNode;
        }else{
            nodePtr = head;
            while (nodePtr->next)
                nodePtr = nodePtr->next;
            nodePtr->next = newNode;
        }
    }
    void displayNode(){
        Node* nodePtr;

        if (!head)
            cout << "Empty" << endl;
        else{
            nodePtr = head;
            while (nodePtr){
                cout << nodePtr->value << " ";
                nodePtr = nodePtr->next;
            }
        }
    }
    void pop(){
        Node* nodePtr = head;
        Node* prevNode = nullptr;

        if (!head){
            cout << "Empty";
            return;
        }
        else if (!head->next){ // If there's only one node in the list
            delete head;
            head = nullptr;
            return;
        }
        else{
            while (nodePtr->next){
                prevNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            delete nodePtr;
            prevNode->next = nullptr;
        }
    }
    void dequeue(){
        Node* nodePtr;

        if (!head){
            cout << "Empty" << endl;
            return;
        }else{
            nodePtr = head;
            head = head->next;
            if (!head)
                back = nullptr;
            delete nodePtr;
        }
    }
};

int main(){
    int user_input = 0;
    int user_num = 0;
    Project obj;

    do{
        cout << "Enter number: ";
        cin >> user_input;

        switch(user_input){
            case 1:
                cout << "Enter data: ";
                cin >> user_num;
                obj.insertNode(user_num);
                break;
            case 2:
                obj.displayNode();
                break;
            case 3:
                obj.pop();
                break;
            case 4:
                obj.dequeue();
                break;
        }
    }while(user_input != 5);
}