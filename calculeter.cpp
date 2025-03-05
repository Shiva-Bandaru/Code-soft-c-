#include <iostream>
using namespace std;

class Calculator {
public:
    void displayMenu() {
        cout << "\n===== Calculator =====\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Modulus (%)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }

    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0) {
            cout << "Error! Division by zero is not allowed." << endl;
            return 0;
        }
        return a / b;
    }
    int modulus(int a, int b) {
        if (b == 0) {
            cout << "Error! Modulus by zero is not allowed." << endl;
            return 0;
        }
        return a % b;
    }
};

int main() {
    Calculator calc;
    int choice;
    double num1, num2;
    
    do {
        calc.displayMenu();
        cin >> choice;

        if (cin.fail()) {  // Check for invalid input
            cin.clear();  // Clear the error flag
            cin.ignore(10000, '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            if (cin.fail()) {  // Validate number inputs
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter valid numbers.\n";
                continue;
            }
        }

        switch (choice) {
            case 1:
                cout << "Result: " << calc.add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << calc.subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << calc.multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << calc.divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Result: " << calc.modulus((int)num1, (int)num2) << endl;
                break;
            case 6:
                cout << "Exiting calculator. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
