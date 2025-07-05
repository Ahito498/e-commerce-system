#include <iostream>
#include "iv/InputValidator.h"
#include "Admin/Admin.h"
#include "Customer/Customer.h"


using namespace std;

int main() {
    while (true) {
        cout << "=============================" << endl;
        cout << " Welcome to E-Commerce System" << endl;
        cout << "=============================" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Customer Login" << endl;
        cout << "3. Customer Sign Up" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice = InputValidator::getValidatedInt(1, 4);

        switch (choice) {
            case 1:
                AdminSession::run();
            break;
            case 2:
                CustomerSession::login();
            break;
            case 3:
                CustomerSession::signUp();
            break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
        }

        cout << endl;
    }
}
