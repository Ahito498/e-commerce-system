#include "Admin.h"
#include "../iv/InputValidator.h"
#include "../Product/Product.h"
#include "../Product/ShippableProduct.h"
#include "../Product/DigitalProduct.h"
#include "Complaint.h"
#include "../Product/ProductStorage.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace AdminSession {
    vector<unique_ptr<Product>> productList;

    bool authenticate() {
        const string correctPassword = "admin123";
        const int maxAttempts = 3;
        int attempts = 0;

        while (attempts < maxAttempts) {
            cout << "Enter admin password: ";
            string password = InputValidator::getNonEmptyString();

            if (password == correctPassword) {
                return true;
            } else {
                attempts++;
                cout << "Invalid password. Attempts left: " << (maxAttempts - attempts) << endl;
            }
        }

        cout << "Too many failed attempts. Returning to main menu." << endl;
        return false;
    }

    void addProduct() {
        cout << "Enter product name: ";
        string name = InputValidator::getNonEmptyString();

        cout << "Enter price: ";
        double price = InputValidator::getValidatedDouble(0);

        cout << "Enter quantity: ";
        int quantity = InputValidator::getValidatedInt(1, 1000000);

        cout << "Is the product shippable?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No (Digital Product)" << endl;
        int shipChoice = InputValidator::getValidatedInt(1, 2);
        bool isShippable = (shipChoice == 1);

        double weight = 0.0;
        if (isShippable) {
            cout << "Enter product weight (kg): ";
            weight = InputValidator::getValidatedDouble(0.001);
        }

        cout << "Does the product have an expiry date?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int expiryChoice = InputValidator::getValidatedInt(1, 2);
        string expiry = "";
        if (expiryChoice == 1) {
            cout << "Enter expiry date (YYYY-MM-DD): ";
            expiry = InputValidator::getNonEmptyString();
        }

        unique_ptr<Product> product;
        if (isShippable) {
            product = make_unique<ShippableProduct>(name, price, quantity, weight);
        } else {
            product = make_unique<DigitalProduct>(name, price, quantity);
        }

        if (!expiry.empty()) {
            product->setExpiryDate(expiry);
        }

        productList.push_back(std::move(product));
        cout << "Product added successfully." << endl;
    }
    void viewAllProducts() {
        if (productList.empty()) {
            cout << "No products available." << endl;
            return;
        }

        cout << "----- Product List -----" << endl;
        for (size_t i = 0; i < productList.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            productList[i]->printDetails(); // this works if everything above is correct
        }
    }
    int selectProduct() {
        if (productList.empty()) {
            cout << "No products available." << endl;
            return -1;
        }

        viewAllProducts();
        cout << "Enter product number: ";
        int choice = InputValidator::getValidatedInt(1, productList.size());
        return choice - 1; // zero-based index
    }

    void removeProduct() {
        int index = selectProduct();
        if (index == -1) return;

        cout << "Are you sure you want to remove: " << productList[index]->getName() << "? (y/n): ";
        string confirm;
        getline(cin, confirm);

        if (confirm == "y" || confirm == "Y") {
            productList.erase(productList.begin() + index);
            cout << "Product removed successfully." << endl;
        } else {
            cout << "Operation cancelled." << endl;
        }
    }
    void restockProduct() {
        int index = selectProduct();
        if (index == -1) return;

        cout << "Enter quantity to add: ";
        int qty = InputValidator::getValidatedInt(1, 1000000);

        // Access protected quantity via reduceQuantity trick
        // OR: add a method like increaseQuantity() if needed
        // For now we'll just cast down and manually adjust
        productList[index]->reduceQuantity(-qty);
        cout << "Product restocked." << endl;
    }
    void changeProductPrice() {
        int index = selectProduct();
        if (index == -1) return;

        cout << "Enter new price: ";
        double newPrice = InputValidator::getValidatedDouble(0);

        // Direct access via protected, or add setter
        productList[index]->setPrice(newPrice);

        cout << "Price updated." << endl;
    }
    void applyDiscount() {
        int index = selectProduct();
        if (index == -1) return;

        cout << "Enter discount percentage (e.g., 10 for 10%): ";
        double percent = InputValidator::getValidatedDouble(0);

        double price = productList[index]->getPrice();
        double discounted = price * (1 - percent / 100.0);
        productList[index]->setPrice(discounted);

        cout << "Discount applied. New price: " << discounted << endl;
    }



    void run() {
        if (!authenticate()) {
            return;
        }
        productList = ProductStorage::loadFromFile("/Users/macstoreeg/Projects/FawryTask/Data/products.txt");


        while (true) {
            cout << "----------------------------" << endl;
            cout << " Admin Menu" << endl;
            cout << "----------------------------" << endl;
            cout << "1. Add Product" << endl;
            cout << "2. Remove Product" << endl;
            cout << "3. Restock Product" << endl;
            cout << "4. Change Product Price" << endl;
            cout << "5. Apply Discount" << endl;
            cout << "6. Remove Expired Products" << endl;
            cout << "7. View Complaints" << endl;
            cout << "8. View All Products" << endl;
            cout << "9. Logout" << endl;
            cout << "Enter your choice: ";

            int choice = InputValidator::getValidatedInt(1, 9);

            switch (choice) {
                case 1: addProduct();break;
                case 2: removeProduct(); break;
                case 3: restockProduct(); break;
                case 4: changeProductPrice(); break;
                case 5: applyDiscount(); break;
                case 6: removeExpiredProducts(); break;
                case 7: viewComplaints(); break;
                case 8: viewAllProducts(); break;
                case 9:
                    cout << "Logging out..." << endl;
                return;
            }
            ProductStorage::saveToFile("/Users/macstoreeg/Projects/FawryTask/Data/products.txt", productList);

            cout << endl;
        }


    }
    void viewComplaints() {
        vector<Complaint> complaints = Complaint::loadFromFile("/Users/macstoreeg/Projects/FawryTask/Data/complaints.txt");

        if (complaints.empty()) {
            cout << "No complaints found." << endl;
            return;
        }

        cout << "Customer Complaints:" << endl;

        for (size_t i = 0; i < complaints.size(); ++i) {
            complaints[i].print();
        }

    }

    void removeExpiredProducts() {
        if (productList.empty()) {
            cout << "No products to check." << endl;
            return;
        }

        int originalSize = productList.size();

        productList.erase(
            remove_if(productList.begin(), productList.end(),
                [](const unique_ptr<Product>& p) {
                    return p->isExpired();
                }),
            productList.end()
        );

        int removed = originalSize - productList.size();
        if (removed == 0) {
            cout << "No expired products found." << endl;
        } else {
            cout << removed << " expired product(s) removed." << endl;
        }
    }
    const std::vector<std::unique_ptr<Product>>& AdminSession::getProductList() {
        return productList = ProductStorage::loadFromFile("/Users/macstoreeg/Projects/FawryTask/Data/products.txt");
    }

}
