#include "DigitalProduct.h"
#include <iostream>

using namespace std;

DigitalProduct::DigitalProduct(string name, double price, int quantity)
    : Product(name, price, quantity) {}

bool DigitalProduct::isShippable() const {
    return false;
}

double DigitalProduct::getWeight() const {
    return 0.0;
}

void DigitalProduct::printDetails() const {
    cout << "Digital Product - " << name
         << ", Price: " << price
         << ", Quantity: " << quantity;

    if (isExpired())
        cout << " (EXPIRED)";
    else if (expiryDate != "")
        cout << ", Expiry: " << expiryDate;

    cout << " (Instant Delivery)" << endl;
}
