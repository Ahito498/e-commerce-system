#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string username;
    string password;
    double balance;

public:
    Customer(string username, string password, double balance);

    string getUsername() const;
    bool checkPassword(const string& input) const;
    double getBalance() const;
    void deduct(double amount);
    void addBalance(double amount);
    void printDetails() const;
    string getPassword() const;

};

namespace CustomerSession {
    void login();
    void signUp();
    void customerMenu();
    void addProductToCart();
    void removeFromCart();
    void checkout();
    void viewOrderHistory();
    void save();
}


#endif
