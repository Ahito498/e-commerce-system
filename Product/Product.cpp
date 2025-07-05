#include "Product.h"
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

Product::Product(string name, double price, int quantity)
    : name(name), price(price), quantity(quantity), hasExpiry(false) {}

string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

void Product::reduceQuantity(int amount) {
    if (amount <= quantity) quantity -= amount;
}

void Product::setExpiryDate(const string& date) {
    hasExpiry = true;
    expiryDate = date;
}

// Basic expiry check assuming date is in YYYY-MM-DD
bool Product::isExpired() const {
    if (!hasExpiry) return false;

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int year, month, day;
    char sep1, sep2;
    stringstream ss(expiryDate);
    ss >> year >> sep1 >> month >> sep2 >> day;

    if (year < currentYear) return true;
    if (year == currentYear && month < currentMonth) return true;
    if (year == currentYear && month == currentMonth && day < currentDay) return true;

    return false;
}
void Product::setPrice(double newPrice) {
    price = newPrice;
}
void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}


string Product::getExpiryDate() const {
    return hasExpiry ? expiryDate : "";
}
