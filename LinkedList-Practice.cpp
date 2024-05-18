#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node *next;
};

Node *head = NULL;

void createNewNode(int user_input){
    Node *newNode, *nodePtr;

    newNode = new Node;
    newNode->value = user_input;
    newNode->next = NULL;

    if (!head)
        head = newNode;
    else{
        nodePtr = head;
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
    cout << "\tThe Node has been successfully created" << endl;
}

void printNode(){
    Node *nodePtr = head;

    if(head==NULL)
        cout << "\tThe Linked List is completely empty" << endl;
    else{
        while(nodePtr){
            cout << "\t";
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
    }
}

void deleteNode(int user_input){
    Node *nodePtr, *nodePrevious;
    int found = 0;

    if(!head){
        cout << "\tThe Linked List is empty: Data cannot be removed" << endl;
        return;
    }
    if(head->value == user_input){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        found = 1;
    }else{
        nodePtr = head;
        nodePrevious = NULL;

        while(nodePtr != NULL){
            if(nodePtr->value == user_input){
                if(nodePrevious == NULL) // if deleting the head
                    head = nodePtr->next;
                else
                    nodePrevious->next = nodePtr->next;
                
                delete nodePtr;
                cout << "\tThe data has been deleted" << endl;
                found = 1;
                break;
            }
            nodePrevious = nodePtr;
            nodePtr = nodePtr->next;
        }
    }
    if (found == 0){
        cout << "\tThe data is not in the Linked List" << endl;
    }
}

void createNewNodeFront(int user_input){
    Node *newNode, *nodePtr;

    newNode = new Node;
    newNode->value = user_input;
    newNode->next = head;
    head = newNode;

    cout << "\tThe Node has been successfully created" << endl;
}

void createNodeChoice(int user_input, int user_node){
    Node *nodePtr, *nodePrevious, *newNode;
    int found = 0;

    if(!head){
        cout << "\tThe Linked List is empty: Data cannot be added" << endl;
        return;
    }
    if(head->value == user_input){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        found = 1;
    }else{
        nodePtr = head;
        nodePrevious = NULL;

        while(nodePtr != NULL){
            if(nodePtr->value == user_input){
                if(nodePrevious == NULL) // if deleting the head
                    head = nodePtr->next;
                else
                    nodePrevious->next = nodePtr->next;
                
                delete nodePtr;
                cout << "\tThe data has been deleted" << endl;
                found = 1;
                break;
            }
            nodePrevious = nodePtr;
            nodePtr = nodePtr->next;
        }
    }
    if (found == 0){
        cout << "\tThe data is not in the Linked List" << endl;
    }
}

int main(){
    int user_choice;
    int user_number;
    Node LinkedList;

    do{
        cout << "\nLinked-List Practice" << endl;
        cout << "\t[1] - Adding Node (Front)" << endl;
        cout << "\t[2] - Adding Node (Back)" << endl;
        cout << "\t[3] - View Node" << endl;
        cout << "\t[4] - Delete Node" << endl;
        cout << "\t[5] - Exit" << endl;
        cout << "Select: ";
        cin >> user_choice;

        switch(user_choice){
            case 1:
                cout << "Enter data to be stored in Front: ";
                cin >> user_number;
                createNewNodeFront(user_number);
                break;
            case 2:
                cout << "Enter data to be stored in the Back: ";
                cin >> user_number;
                createNewNode(user_number);
                break;
            case 3:
                cout << "Linked-List Data: " << endl;
                printNode();
                break;
            case 4:
                cout << "Enter data to be deleted: ";
                cin >> user_number;
                deleteNode(user_number);
                break;
            default:
                cout << "Please Enter Valid Input" << endl;
        }
    }while(user_choice != 5);

    return 0;
}
