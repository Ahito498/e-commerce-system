#include "Cart.h"
#include <iostream>

using namespace std;

void Cart::addItem(Product* product, int quantity) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getProduct() == product) {
            int newQty = items[i].getQuantity() + quantity;
            items[i].setQuantity(newQty);
            return;
        }
    }
    items.push_back(CartItem(product, quantity));
}

void Cart::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        items.erase(items.begin() + index);
    }
}

void Cart::viewCart() const {
    if (items.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }

    cout << "----- Your Cart -----" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        Product* p = items[i].getProduct();
        cout << "[" << i + 1 << "] " << p->getName()
             << " | Price: " << p->getPrice()
             << " | Quantity: " << items[i].getQuantity()
             << " | Subtotal: " << items[i].getTotalPrice() << endl;
    }
}

double Cart::calculateSubtotal() const {
    double total = 0;
    for (size_t i = 0; i < items.size(); ++i) {
        total += items[i].getTotalPrice();
    }
    return total;
}

bool Cart::isEmpty() const {
    return items.empty();
}

void Cart::clear() {
    items.clear();
}

const vector<CartItem>& Cart::getItems() const {
    return items;
}
