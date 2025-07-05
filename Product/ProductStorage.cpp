#include "ProductStorage.h"
#include "ShippableProduct.h"
#include "DigitalProduct.h"
#include <fstream>
#include <iostream>

using namespace std;

void ProductStorage::saveToFile(const string& filename, const vector<unique_ptr<Product>>& list) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing: " << filename << endl;
        return;
    }

    for (const auto& product : list) {
        if (product->isShippable()) {
            file << "Shippable\n";
        } else {
            file << "Digital\n";
        }

        file << product->getName() << '\n';
        file << product->getPrice() << '\n';
        file << product->getQuantity() << '\n';
        file << product->getWeight() << '\n';

        if (product->isExpired()) {
            file << product->isExpired() << '\n'; // still save expired date
        } else if (!product->isExpired() && product->getExpiryDate() != "") {
            file << product->getExpiryDate() << '\n';
        } else {
            file << "none\n";
        }
    }

    file.close();
}

vector<unique_ptr<Product>> ProductStorage::loadFromFile(const string& filename) {
    vector<unique_ptr<Product>> list;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Product file not found. Starting with empty store." << endl;
        return list;
    }

    string type;
    while (getline(file, type)) {
        string name, priceStr, qtyStr, weightStr, expiry;
        if (!getline(file, name)) break;
        if (!getline(file, priceStr)) break;
        if (!getline(file, qtyStr)) break;
        if (!getline(file, weightStr)) break;
        if (!getline(file, expiry)) break;

        double price = stod(priceStr);
        int quantity = stoi(qtyStr);
        double weight = stod(weightStr);

        unique_ptr<Product> product;
        if (type == "Shippable") {
            product = make_unique<ShippableProduct>(name, price, quantity, weight);
        } else {
            product = make_unique<DigitalProduct>(name, price, quantity);
        }

        if (expiry != "none") {
            product->setExpiryDate(expiry);
        }

        list.push_back(std::move(product));
    }

    file.close();
    return list;
}
