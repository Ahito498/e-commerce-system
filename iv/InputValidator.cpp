#include "InputValidator.h"
#include <iostream>
#include <limits>

using namespace std;
namespace InputValidator {

    int getValidatedInt(int min, int max) {
        int value;
        while (true) {
            cout << "> ";
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
            } else if (value < min || value > max) {
                cout << "Input out of range. Must be between " << min << " and " << max << ".\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    double getValidatedDouble(double min) {
        double value;
        while (true) {
            cout << "> ";
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
            } else if (value < min) {
                cout << "Number must be at least " << min << ".\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    string getNonEmptyString() {
        string input;
        while (true) {
            getline(cin, input);
            if (input.empty()) {
                cout << "Input cannot be empty. Please try again.\n> ";
            } else {
                return input;
            }
        }
    }

}
