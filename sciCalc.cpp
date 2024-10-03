#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

//define all scientific operations in fuctions
bool allowedOperator(char operator_);
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double division(double num1, double num2);
double multiplication(double num1, double num2);
int modulous(double num1, double num2);
double power(double num1, double num2);


int main () {
    cout << "welcome to a scientific calculator\n";
    double num1;
    double num2;
    char operator_;
    cout << "enter your equation in infix notation: ";
    while(!(cin >> num1 >> operator_ >> num2)){
        bool allowed = allowedOperator(operator_);
        while(allowed == false){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid operator. try again: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalud number input. try again: ";
    }
    cout << num1 << " " << operator_ << " " << num2 << '\n';

    double answer;
    cout << "answer: ";
    if(operator_ == '+'){
        double answer = addition(num1, num2);
    }
    else if(operator_ == '-'){
        cout << operator_ << '\n';
        double answer = subtraction(num1, num2);
    }
    else if(operator_ == '/'){
        cout << operator_ << '\n';
        double answer = division(num1, num2);
    }
    else if(operator_ == '*'){
        cout << operator_ << '\n';
        double answer = multiplication(num1, num2);
    }
    else if(operator_ == '%'){
        cout << operator_ << '\n';
        int answer = modulous(num1, num2);
    }
    else{
        cout << operator_ << '\n';
        double answer = power(num1, num2);
    }

    cout << '\n';
    return 0;
}

//checks to see if the operator is allowed 
bool allowedOperator(char operator_){
    bool allowed;
    char inOperator = operator_;
    char allowedOperators[] = {'+', '-', '*', '/', '%', '^'};

    if (any_of(allowedOperators, allowedOperators + 6, 
            [&](char x){return x == inOperator;})){
        allowed = true;
    }
    else{
        allowed = false;
    }
    return allowed;
}
//fuctions of different operations taking in the two inputted numbers
double addition(double num1, double num2){
    double numOne = num1;
    double numTwo = num2;
    double answer = numOne + numTwo;
    cout << answer;
    return answer;
}
double subtraction(double num1, double num2){
    double numOne = num1;
    double numTwo = num2;
    cout << numOne << " " << numTwo << '\n';
    double answer = numOne - numTwo;
    return answer;
}
double division(double num1, double num2){
    double numOne = num1;
    double numTwo = num2;
    cout << numOne << " " << numTwo << '\n';
    double answer = numOne/numTwo;
    return answer;
}
double multiplication(double num1, double num2){
    double numOne = num1;
    double numTwo = num2;
    cout << numOne << " " << numTwo << '\n';
    double answer = numOne*numTwo;
    return answer;
}
int modulous(double num1, double num2){
    cout << "entered numbers with decimals will be truncated\n";
    int numOne = num1;
    int numTwo = num2;
    cout << numOne << " " << numTwo << '\n';
    int answer = numOne % numTwo;
    return answer;
}
double power(double num1, double num2){
    double numOne = num1;
    double numTwo = num2;
    cout << numOne << " " << numTwo << '\n';
    double answer = pow(numOne, numTwo);
    return answer;
}