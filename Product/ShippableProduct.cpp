#include "ShippableProduct.h"
#include <iostream>

using namespace std;

ShippableProduct::ShippableProduct(string name, double price, int quantity, double weight)
    : Product(name, price, quantity), weight(weight) {}

bool ShippableProduct::isShippable() const {
    return true;
}

double ShippableProduct::getWeight() const {
    return weight;
}

string ShippableProduct::getName() const {
    return name;
}

void ShippableProduct::printDetails() const {
    cout << "Shippable Product - " << name
         << ", Price: " << price
         << ", Quantity: " << quantity
         << ", Weight: " << weight << "kg";

    if (isExpired())
        cout << " (EXPIRED)";
    else if (expiryDate != "")
        cout << ", Expiry: " << expiryDate;

    cout << endl;
}
