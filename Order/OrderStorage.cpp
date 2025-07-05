#include "OrderStorage.h"
#include <fstream>
#include <iostream>

using namespace std;

void OrderStorage::saveOrder(const string& filename, const string& customerUsername, const vector<CartItem>& items, double shipping, double total) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Could not open order file for writing." << endl;
        return;
    }

    file << "Customer: " << customerUsername << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        Product* product = items[i].getProduct();
        file << "- " << product->getName()
             << " | Qty: " << items[i].getQuantity()
             << " | Price: " << product->getPrice()
             << " | Subtotal: " << items[i].getTotalPrice() << endl;
    }

    file << "Shipping: " << shipping << endl;
    file << "Total: " << total << endl;
    file << "-----------------------------" << endl;

    file.close();
}
