#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;

    bool hasExpiry;
    string expiryDate; // format: YYYY-MM-DD

public:
    Product(string name, double price, int quantity);
    virtual ~Product() = default;

    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int quantity);


    void reduceQuantity(int amount);
    void setExpiryDate(const string& date);
    bool isExpired() const;

    virtual bool isShippable() const = 0;
    virtual double getWeight() const = 0;
    virtual void printDetails() const = 0;
    void setPrice(double newPrice);
    string getExpiryDate() const;


};

#endif