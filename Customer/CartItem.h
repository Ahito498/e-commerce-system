#ifndef CART_ITEM_H
#define CART_ITEM_H

#include "../Product/Product.h"

class CartItem {
private:
    Product* product;   // non-owning pointer
    int quantity;

public:
    CartItem(Product* product, int quantity);

    Product* getProduct() const;
    int getQuantity() const;
    double getTotalPrice() const;

    void setQuantity(int quantity);
};

#endif
