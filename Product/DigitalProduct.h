#ifndef DIGITAL_PRODUCT_H
#define DIGITAL_PRODUCT_H

#include "Product.h"

class DigitalProduct : public Product {
public:
    DigitalProduct(string name, double price, int quantity);

    bool isShippable() const override;
    double getWeight() const override;
    void printDetails() const override;
};

#endif
