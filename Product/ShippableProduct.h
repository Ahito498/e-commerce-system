#ifndef SHIPPABLE_PRODUCT_H
#define SHIPPABLE_PRODUCT_H

#include "Product.h"

class ShippableProduct : public Product {
private:
    double weight;

public:
    ShippableProduct(string name, double price, int quantity, double weight);

    bool isShippable() const override;
    double getWeight() const override;
    string getName() const;
    void printDetails() const override;

};

#endif
