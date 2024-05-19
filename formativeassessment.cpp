#include <iostream>
#include <cctype>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int questionNum = 1;
int score = 0;
string userAnswer;
bool askedQuestions[10] = {false}; // Array to keep track of asked questions

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();

void loop();

int main(){
    cout << "\nFormative Assessment: " << endl;

    do{
        loop();
    } while (questionNum != 10);

    cout << "\nScore: " << score;

    return 0;
}


void question1(){
    cout << "\nWhat is 0 + 0 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;
    
    if (userAnswer == "0"){
        score++;
    }
}
void question2(){
    cout << "\nWhat is 1 + 1 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "2"){
        score++;
    }
}
void question3(){
    cout << "\nWhat is 2 + 2 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "4"){
        score++;
    }
}
void question4(){
    cout << "\nWhat is 3 + 3 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "6"){
        score++;
    }
}
void question5(){
    cout << "\nWhat is 4 + 4 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "8"){
        score++;
    }
}
void question6(){
    cout << "\nWhat is 5 + 5 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "10"){
        score++;
    }
}
void question7(){
    cout << "\nWhat is 6 + 6 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "12"){
        score++;
    }
}
void question8(){
    cout << "\nWhat is 7 + 7 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "14"){
        score++;
    }
}
void question9(){
    cout << "\nWhat is 8 + 8 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "16"){
        score++;
    }
}
void question10(){
    cout << "\nWhat is 9 + 9 ?" << endl;
    cout << "Answer: ";
    cin >> userAnswer;

    if (userAnswer == "18"){
        score++;
    }
}

void loop(){
    unsigned int randomizer = static_cast<unsigned int>(time(nullptr));
    srand(randomizer);

    int num;
    do {
        num = rand() % 10 + 1;
    } while (askedQuestions[num - 1]); // Check if the question has been asked before

    askedQuestions[num - 1] = true; // Mark the question as asked

    switch (num){
        case 1:
            cout << "\nQuestion: " << questionNum << endl;
            question1();
            break;
        case 2:
            cout << "\nQuestion: " << questionNum << endl;
            question2();
            break;
        case 3:
            cout << "\nQuestion: " << questionNum << endl;
            question3();
            break;
        case 4:
            cout << "\nQuestion: " << questionNum << endl;
            question4();
            break;
        case 5:
            cout << "\nQuestion: " << questionNum << endl;
            question5();
            break;
        case 6:
            cout << "\nQuestion: " << questionNum << endl;
            question6();
            break;
        case 7:
            cout << "\nQuestion: " << questionNum << endl;
            question7();
            break;
        case 8:
            cout << "\nQuestion: " << questionNum << endl;
            question8();
            break;
        case 9:
            cout << "\nQuestion: " << questionNum << endl;
            question9();
            break;
        case 10:
            cout << "\nQuestion: " << questionNum << endl;
            question10();
            break;
    }

    questionNum++;
}