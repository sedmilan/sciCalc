#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>

/*  You were doing prototypes earlier they just looked weird
    This is a different take but its more clean and isnt redundant 
    also your bool logic was wrong kind of, for one you dont have 
    create a variable to set equal to your parameter you just use 
    it as is. Also return can act as a true/false in some cases 
    you should look into that makes things smooth. Also the begin and 
    end functions there that im using are pointers to the start and end 
    of the array. No need to hardcode that stuff in. 
    they was we check for validity is slightly different but nothing 
    was changed ouragouly there in terms of logic.
    Lastly you will notice I got rid of "using namespace std;"
    nothing really wrong with that but you will end up not using it in the future 
    if you want me to explain the reasoning i can or you can look it up 
    but its best to use std::cout << "taco" << std::endl;
      "std::"  use that 

    alright i tried to cover most things idk if youre gonna read this but yeah
*/
// checking if operator input is valid
bool allowedOperator(char operator_) {
    char allowedOperators[] = { '+', '-', '*', '/', '%', '^' };
    return std::any_of(std::begin(allowedOperators), std::end(allowedOperators),
        [&](char x) { return x == operator_; });
}

// Function prototypes
// Functions are inlined as well
double addition(double a, double b) { return a + b; }
double subtraction(double a, double b) { return a - b; }
double multiplication(double a, double b) { return a * b; }
double division(double a, double b) { return a / b; }
int modulous(int a, int b) { return a % b; }
double power(double a, double b) { return std::pow(a, b); }

int main() {
    std::cout << "Welcome to the scientific calculator\n";

    double num1, num2, answer = 0;
    char operator_;
    bool validInput = false;

    // Main input loop
    while (!validInput) {
        std::cout << "Enter your equation in infix notation (example: 5 + 3): ";

        if (std::cin >> num1 >> operator_ >> num2) {
            // Validate the operator
            if (allowedOperator(operator_)) {
                validInput = true;
            }
                // invalid operator input
            else {
                std::cout << "Invalid operator. Please try again.\n";
            }
        }
        else {
            // Invalid number input
            std::cout << "Invalid number input. Please try again.\n";
        }
        // clear and discards things in the buffer, setting us up for another user input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Perform the operation based on the operator
    // When working with multiple cases Sean its best to use a switch statement
    switch (operator_) {
    case '+':
        answer = addition(num1, num2);
        break;
    case '-':
        answer = subtraction(num1, num2);
        break;
    case '*':
        answer = multiplication(num1, num2);
        break;
    case '/':
        if (num2 != 0) {
            answer = division(num1, num2);
        }
        else {
            std::cout << "Error: Division by zero is undefined.\n";
            return 1;
        }
        break;
    case '%':
        if (static_cast<int>(num2) != 0) {
            answer = modulous(static_cast<int>(num1), static_cast<int>(num2));
        }
        else {
            std::cout << "Error: Modulus by zero is undefined.\n";
            return 1;
        }
        break;
    case '^':
        answer = power(num1, num2);
        break;
    default:
        std::cout << "Error: Unknown operator.\n";
        return 1;
    }
    // output into terminal
    std::cout << "Answer: " << answer << '\n';

    return 0;
}