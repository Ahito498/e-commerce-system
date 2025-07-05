#ifndef CART_H
#define CART_H

#include "CartItem.h"
#include <vector>

class Cart {
private:
    std::vector<CartItem> items;

public:
    void addItem(Product* product, int quantity);
    void removeItem(int index);
    void viewCart() const;
    double calculateSubtotal() const;
    bool isEmpty() const;
    void clear();
    const std::vector<CartItem>& getItems() const;
};

#endif
