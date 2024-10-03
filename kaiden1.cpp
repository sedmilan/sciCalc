#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// function definitions
bool allowedOperator(char operator_);
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double division(double num1, double num2);
double multiplication(double num1, double num2);
int my_modulus(double num1, double num2);
double power(double num1, double num2);


int main()
{
    // retrieve input
    double num1;
    double num2;
    char operator_;

    cout << "welcome to a scientific calculator\n";
    cout << "enter your equation in infix notation: ";

    while (!(cin >> num1 >> operator_ >> num2) || !allowedOperator(operator_))
    {
        if (!allowedOperator(operator_))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid operator. try again: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalud number input. try again: ";
    }
    cout << num1 << " " << operator_ << " " << num2 << '\n';

    // compute answer
    double answer;
    cout << "answer: ";
    switch (operator_)
    {
        case '+':
            answer = addition(num1, num2);
            break;
        case '-':
            answer = subtraction(num1, num2);
            break;
        case '/':
            answer = multiplication(num1, num2);
            break;
        case '*':
            answer = power(num1, num2);
            break;
        case '%':
            answer = my_modulus(num1, num2);
            break;
        case '^':
            answer = power(num1, num2);
            break;
        default:
            break;
    }

    cout << answer << '\n';


    return 0;
}

//checks to see if the operator is allowed
bool allowedOperator(char operator_)
{
    return operator_ == '+' || operator_ == '-' || operator_ == '*' || operator_ == '/' || operator_ == '%' || operator_ == '^';
}

//fuctions of different operations taking in the two inputted numbers
double addition(double num1, double num2)
{
    double numOne = num1;
    double numTwo = num2;
    double answer = numOne + numTwo;
    return answer;
}

double subtraction(double num1, double num2)
{
    double numOne = num1;
    double numTwo = num2;
    double answer = numOne - numTwo;
    return answer;
}

double division(double num1, double num2)
{
    double numOne = num1;
    double numTwo = num2;
    double answer = numOne / numTwo;
    return answer;
}

double multiplication(double num1, double num2)
{
    double numOne = num1;
    double numTwo = num2;
    double answer = numOne * numTwo;
    return answer;
}

int my_modulus(double num1, double num2)
{
    cout << "entered numbers with decimals will be truncated\n";
    int numOne = num1;
    int numTwo = num2;
    int answer = numOne % numTwo;
    return answer;
}

double power(double num1, double num2)
{
    double numOne = num1;
    double numTwo = num2;
    double answer = pow(numOne, numTwo);
    return answer;
}