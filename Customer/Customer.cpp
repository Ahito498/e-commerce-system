#include "Customer.h"

#include <fstream>

#include "CustomerStorage.h"
#include "../iv/InputValidator.h"
#include "../Customer//Cart.h"
#include "../Product/Product.h"
#include "../Admin/Admin.h"
#include "../Shipping/ShippingService.h"
#include "../Product/ShippableProduct.h"
#include "..//Customer/CartItem.h"
#include "..//Order/OrderStorage.h"

#include <iostream>
#include <vector>
using namespace std;

Customer::Customer(string username, string password, double balance)
    : username(username), password(password), balance(balance) {}

string Customer::getUsername() const {
    return username;
}

bool Customer::checkPassword(const string& input) const {
    return password == input;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::deduct(double amount) {
    balance -= amount;
}

void Customer::addBalance(double amount) {
    balance += amount;
}

void Customer::printDetails() const {
    cout << "Username: " << username << ", Balance: " << balance << endl;
}

string Customer::getPassword() const {
        return password;

}


namespace CustomerSession {

    vector<Customer> customers = CustomerStorage::loadFromFile("../Data/customers.txt");
    Cart cart;
    Customer* loggedInCustomer = nullptr;

    void save() {
        CustomerStorage::saveToFile("../Data/customers.txt", customers);
    }

    void login() {
        cout << "Enter your username: ";
        string username = InputValidator::getNonEmptyString();

        int index = CustomerStorage::findCustomerIndex(customers, username);
        if (index == -1) {
            cout << "Customer not found." << endl;
            return;
        }

        cout << "Enter your password: ";
        string password = InputValidator::getNonEmptyString();

        if (!customers[index].checkPassword(password)) {
            cout << "Incorrect password." << endl;
            return;
        }

        loggedInCustomer = &customers[index];

        cout << "Login successful." << endl;
        loggedInCustomer->printDetails();
        customerMenu();

    }

    void signUp() {
        cout << "Enter a username: ";
        string username = InputValidator::getNonEmptyString();

        int index = CustomerStorage::findCustomerIndex(customers, username);
        if (index != -1) {
            cout << "Username already exists. Try logging in." << endl;
            return;
        }

        cout << "Enter a password: ";
        string password = InputValidator::getNonEmptyString();

        cout << "Enter starting balance: ";
        double balance = InputValidator::getValidatedDouble(0);

        customers.push_back(Customer(username, password, balance));
        save();
        cout << "Sign-up successful. You can now log in." << endl;

    }

    void addProductToCart() {
        const vector<unique_ptr<Product>>& products = AdminSession::getProductList();

        if (products.empty()) {
            cout << "No products available." << endl;
            return;
        }

        cout << "----- All Products -----" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            Product* p = products[i].get();
            cout << "[" << i + 1 << "] " << p->getName()
                 << " | Price: " << p->getPrice()
                 << " | Quantity: " << p->getQuantity();

            if (p->isExpired()) cout << " | EXPIRED";
            cout << endl;
        }

        cout << "Select product number to add: ";
        int index = InputValidator::getValidatedInt(1, products.size()) - 1;

        Product* selected = products[index].get();

        if (selected->isExpired()) {
            cout << "Cannot add expired product." << endl;
            return;
        }

        if (selected->getQuantity() == 0) {
            cout << "Product is out of stock." << endl;
            return;
        }

        cout << "Enter quantity to add: ";
        int qty = InputValidator::getValidatedInt(1, selected->getQuantity());

        cart.addItem(selected, qty);
        cout << "Added to cart." << endl;
    }

    void removeFromCart() {
        if (cart.isEmpty()) {
            cout << "Cart is empty." << endl;
            return;
        }

        cart.viewCart();
        cout << "Enter item number to remove: ";
        int index = InputValidator::getValidatedInt(1, cart.getItems().size()) - 1;

        cart.removeItem(index);
        cout << "Item removed." << endl;
    }

void checkout() {
    if (cart.isEmpty()) {
        cout << "Cart is empty. Cannot proceed to checkout." << endl;
        return;
    }

    double subtotal = cart.calculateSubtotal();
    double shippingCost = 0;

    vector<ShippableProduct*> shippableItems;

    const vector<CartItem>& items = cart.getItems();

    for (size_t i = 0; i < items.size(); ++i) {
        Product* product = items[i].getProduct();

        if (product->isExpired()) {
            cout << "Error: Product '" << product->getName() << "' is expired. Remove it from cart first." << endl;
            return;
        }

        if (items[i].getQuantity() > product->getQuantity()) {
            cout << "Error: Not enough stock for '" << product->getName() << "'." << endl;
            return;
        }

        if (product->isShippable()) {
            ShippableProduct* item = dynamic_cast<ShippableProduct*>(product);
            if (item != nullptr) {
                shippableItems.push_back(item);
                shippingCost += item->getWeight() * 5; // example: $5 per kg
            }
        }
    }

    double total = subtotal + shippingCost;

    cout << "Subtotal: " << subtotal << endl;
    cout << "Shipping: " << shippingCost << endl;
    cout << "Total:    " << total << endl;

    if (loggedInCustomer->getBalance() < total) {
        cout << "Insufficient balance." << endl;
        return;
    }

    // Deduct from balance
    loggedInCustomer->deduct(total);

    // Deduct product quantities
    for (size_t i = 0; i < items.size(); ++i) {
        Product* product = items[i].getProduct();
        int newQty = product->getQuantity() - items[i].getQuantity();
        product->setQuantity(newQty);
    }

    // Ship items
    if (!shippableItems.empty()) {
        ShippingService::shipItems(shippableItems);
    }

    // ✅ Final Order Summary (before clearing cart)
    cout << "\n========== ORDER SUMMARY ==========" << endl;

    for (size_t i = 0; i < items.size(); ++i) {
        Product* product = items[i].getProduct();
        cout << "- " << product->getName()
             << " | Quantity: " << items[i].getQuantity()
             << " | Price: " << product->getPrice()
             << " | Subtotal: " << items[i].getTotalPrice() << endl;
    }

    cout << "-----------------------------------" << endl;
    cout << "Shipping: " << shippingCost << endl;
    cout << "Total Paid: " << total << endl;
    cout << "New Balance: " << loggedInCustomer->getBalance() << endl;
    cout << "===================================" << endl;

    // Clear cart
    cart.clear();

    cout << "\nOrder placed successfully." << endl;

    // Save order to file
    OrderStorage::saveOrder("../Data/orders.txt",
                            loggedInCustomer->getUsername(),
                            items,
                            shippingCost,
                            total);
}

    void viewOrderHistory() {
        if (loggedInCustomer == nullptr) {
            cout << "No customer logged in." << endl;
            return;
        }

        ifstream file("../Data/orders.txt");
        if (!file.is_open()) {
            cout << "No order history found." << endl;
            return;
        }

        string line;
        bool found = false;
        bool printing = false;

        string header = "Customer: " + loggedInCustomer->getUsername();

        while (getline(file, line)) {
            if (line.find("Customer: ") == 0) {
                printing = (line == header);
                if (printing) {
                    found = true;
                    cout << "\n--- Order ---" << endl;
                    cout << line << endl;
                }
            } else if (printing) {
                cout << line << endl;
            }
        }

        file.close();

        if (!found) {
            cout << "No previous orders found for your account." << endl;
        }
    }


    void customerMenu() {
        int choice;
        do {
            cout << "\n--- Customer Menu ---" << endl;
            cout << "1. View Products" << endl;
            cout << "2. Add Product to Cart" << endl;
            cout << "3. View Cart" << endl;
            cout << "4. Remove Item from Cart" << endl;
            cout << "5. Checkout" << endl;
            cout << "6. View Order History" << endl;
            cout << "0. Logout" << endl;

            choice = InputValidator::getValidatedInt(0, 6);

            switch (choice) {
                case 1:
                    AdminSession::viewAllProducts();
                break;
                case 2:
                    addProductToCart();
                break;
                case 3:
                    cart.viewCart();
                break;
                case 4:
                    removeFromCart();
                break;
                case 5:
                    checkout();
                break;
                case 6:
                    viewOrderHistory();
                break;

            }
        } while (choice != 0);

        loggedInCustomer = nullptr;
        cart.clear();
        cout << "Logged out." << endl;
    }

}
