#include<iostream>
using namespace std;

char arr_word[5] = {};
bool word_checker();

int main(){
    do{
        cout << "Enter a Word: ";
        for(int i = 0; i < 5; i++){
            cin >> arr_word[i];
        }
    }while(!word_checker());
    cout << "You Got The Correct Answer!" << endl;
    return 0;
}

bool word_checker(){
    bool firstLetter = false;
    bool secondLetter = false;
    bool thirdLetter = false;
    bool fourthLetter = false;
    bool fifthLetter = false;
    
    if(arr_word[0] == 'H'){
        firstLetter = true;
    }
    if(arr_word[1] == 'E'){
        secondLetter = true;
    }
    if(arr_word[2] == 'L'){
        thirdLetter = true;
    }
    if(arr_word[3] == 'L'){
        fourthLetter = true;
    }
    if(arr_word[4] == 'O'){
        fifthLetter = true;
    }
    
    if(!firstLetter){
        cout << "\t\t0 ";
    }else{
        cout << "\t\t1 ";
    }
    
    if(!secondLetter){
        cout << "0 ";
    }else{
        cout << "1 ";
    }
    
    if(!thirdLetter){
        cout << "0 ";
    }else{
        cout << "1 ";
    }
    
    if(!fourthLetter){
        cout << "0 ";
    }else{
        cout << "1 ";
    }
    
    if(!fifthLetter){
        cout << "0 " << endl;
    }else{
        cout << "1 " << endl;
    }

    return firstLetter && secondLetter && thirdLetter && fourthLetter && firstLetter;
}