#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "../include/Product.h"
#include "../include/User.h"
#include "../include/Cart.h"
#include "../include/Admin.h"
#include "../include/Utils.h"

// Global data
std::vector<Product> products;
std::vector<User> users;
User* currentUser = nullptr;
Cart currentCart;

// Function declarations
void loadData();
void saveData();
void showMainMenu();
void showUserMenu();
void showGuestMenu();
void handleLogin();
void handleRegistration();
void handleProductBrowsing();
void handleShoppingCart();
void handleUserProfile();
void handleAdminPanel();

int main() {
    std::cout << "Welcome to E-Commerce System!" << std::endl;
    std::cout << "Loading data..." << std::endl;
    
    // Load data from files
    loadData();
    
    // Main application loop
    bool running = true;
    while (running) {
        if (currentUser == nullptr) {
            showGuestMenu();
        } else if (currentUser->getIsAdmin()) {
            showMainMenu();
        } else {
            showUserMenu();
        }
    }
    
    // Save data before exiting
    saveData();
    std::cout << "Thank you for using E-Commerce System!" << std::endl;
    return 0;
}

void loadData() {
    // Load products
    std::ifstream productFile("data/products.txt");
    if (productFile.is_open()) {
        std::string line;
        while (std::getline(productFile, line)) {
            if (!line.empty()) {
                products.push_back(Product::fromFileString(line));
            }
        }
        productFile.close();
    }
    
    // Load users
    std::ifstream userFile("data/users.txt");
    if (userFile.is_open()) {
        std::string line;
        while (std::getline(userFile, line)) {
            if (!line.empty()) {
                users.push_back(User::fromFileString(line));
            }
        }
        userFile.close();
    }
    
    // Create default admin if no users exist
    if (users.empty()) {
        User admin(1, "admin", "admin123", "admin@ecommerce.com", "System Administrator");
        admin.setIsAdmin(true);
        users.push_back(admin);
    }
}

void saveData() {
    // Save products
    std::ofstream productFile("data/products.txt");
    if (productFile.is_open()) {
        for (const auto& product : products) {
            productFile << product.toFileString() << std::endl;
        }
        productFile.close();
    }
    
    // Save users
    std::ofstream userFile("data/users.txt");
    if (userFile.is_open()) {
        for (const auto& user : users) {
            userFile << user.toFileString() << std::endl;
        }
        userFile.close();
    }
}

void showMainMenu() {
    Utils::clearScreen();
    Utils::printHeader("E-Commerce System - Main Menu");
    
    std::vector<std::string> options = {
        "Browse Products",
        "View Shopping Cart",
        "User Profile",
        "Admin Panel",
        "Logout",
        "Exit"
    };
    
    int choice = Utils::getMenuChoice(options);
    
    switch (choice) {
        case 1:
            handleProductBrowsing();
            break;
        case 2:
            handleShoppingCart();
            break;
        case 3:
            handleUserProfile();
            break;
        case 4:
            if (currentUser->getIsAdmin()) {
                handleAdminPanel();
            } else {
                Utils::printError("Access denied. Admin privileges required.");
            }
            break;
        case 5:
            currentUser = nullptr;
            currentCart.clear();
            Utils::printSuccess("Logged out successfully.");
            break;
        case 6:
            exit(0);
            break;
        default:
            Utils::printError("Invalid choice. Please try again.");
    }
}

void showUserMenu() {
    Utils::clearScreen();
    Utils::printHeader("E-Commerce System - User Menu");
    
    std::vector<std::string> options = {
        "Browse Products",
        "View Shopping Cart",
        "User Profile",
        "Logout",
        "Exit"
    };
    
    int choice = Utils::getMenuChoice(options);
    
    switch (choice) {
        case 1:
            handleProductBrowsing();
            break;
        case 2:
            handleShoppingCart();
            break;
        case 3:
            handleUserProfile();
            break;
        case 4:
            currentUser = nullptr;
            currentCart.clear();
            Utils::printSuccess("Logged out successfully.");
            break;
        case 5:
            exit(0);
            break;
        default:
            Utils::printError("Invalid choice. Please try again.");
    }
}

void showGuestMenu() {
    Utils::clearScreen();
    Utils::printHeader("E-Commerce System - Guest Menu");
    
    std::vector<std::string> options = {
        "Browse Products",
        "Login",
        "Register",
        "Exit"
    };
    
    int choice = Utils::getMenuChoice(options);
    
    switch (choice) {
        case 1:
            handleProductBrowsing();
            break;
        case 2:
            handleLogin();
            break;
        case 3:
            handleRegistration();
            break;
        case 4:
            exit(0);
            break;
        default:
            Utils::printError("Invalid choice. Please try again.");
    }
}

void handleLogin() {
    Utils::clearScreen();
    Utils::printHeader("Login");
    
    std::string username = Utils::getValidString("Enter username: ");
    std::string password = Utils::getValidString("Enter password: ");
    
    // Find user
    for (auto& user : users) {
        if (user.getUsername() == username && user.authenticate(password)) {
            if (user.getIsActive()) {
                currentUser = &user;
                Utils::printSuccess("Login successful! Welcome, " + user.getFullName());
                return;
            } else {
                Utils::printError("Account is deactivated. Please contact administrator.");
                return;
            }
        }
    }
    
    Utils::printError("Invalid username or password.");
}

void handleRegistration() {
    Utils::clearScreen();
    Utils::printHeader("User Registration");
    
    std::string username = Utils::getValidString("Enter username: ");
    std::string password = Utils::getValidString("Enter password: ");
    std::string email = Utils::getValidEmail("Enter email: ");
    std::string fullName = Utils::getValidString("Enter full name: ");
    
    // Check if username already exists
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            Utils::printError("Username already exists. Please choose another.");
            return;
        }
    }
    
    // Create new user
    int newUserId = users.size() + 1;
    User newUser(newUserId, username, password, email, fullName);
    users.push_back(newUser);
    
    Utils::printSuccess("Registration successful! You can now login.");
}

void handleProductBrowsing() {
    Utils::clearScreen();
    Utils::printHeader("Product Catalog");
    
    if (products.empty()) {
        Utils::printInfo("No products available.");
        return;
    }
    
    // Display products
    for (const auto& product : products) {
        product.displayShort();
    }
    
    std::vector<std::string> options = {
        "Add to Cart",
        "Search Products",
        "Filter by Category",
        "Back to Menu"
    };
    
    int choice = Utils::getMenuChoice(options);
    
    switch (choice) {
        case 1: {
            int productId = Utils::getValidInt("Enter product ID to add to cart: ");
            int quantity = Utils::getValidInt("Enter quantity: ", 1);
            
            auto it = std::find_if(products.begin(), products.end(),
                                  [productId](const Product& p) { return p.getId() == productId; });
            
            if (it != products.end()) {
                if (currentCart.addItem(*it, quantity)) {
                    Utils::printSuccess("Product added to cart successfully!");
                } else {
                    Utils::printError("Failed to add product to cart.");
                }
            } else {
                Utils::printError("Product not found.");
            }
            break;
        }
        case 2: {
            std::string query = Utils::getValidString("Enter search term: ");
            // TODO: Implement search functionality
            Utils::printInfo("Search functionality coming soon!");
            break;
        }
        case 3: {
            std::string category = Utils::getValidString("Enter category: ");
            // TODO: Implement category filtering
            Utils::printInfo("Category filtering coming soon!");
            break;
        }
        case 4:
            return;
    }
}

void handleShoppingCart() {
    Utils::clearScreen();
    Utils::printHeader("Shopping Cart");
    
    if (currentCart.isEmpty()) {
        Utils::printInfo("Your cart is empty.");
        return;
    }
    
    currentCart.display();
    
    std::vector<std::string> options = {
        "Update Quantity",
        "Remove Item",
        "Checkout",
        "Clear Cart",
        "Back to Menu"
    };
    
    int choice = Utils::getMenuChoice(options);
    
    switch (choice) {
        case 1: {
            int productId = Utils::getValidInt("Enter product ID: ");
            int quantity = Utils::getValidInt("Enter new quantity: ", 1);
            
            if (currentCart.updateQuantity(productId, quantity)) {
                Utils::printSuccess("Quantity updated successfully!");
            } else {
                Utils::printError("Failed to update quantity.");
            }
            break;
        }
        case 2: {
            int productId = Utils::getValidInt("Enter product ID to remove: ");
            
            if (currentCart.removeItem(productId)) {
                Utils::printSuccess("Item removed from cart!");
            } else {
                Utils::printError("Failed to remove item.");
            }
            break;
        }
        case 3: {
            if (currentUser == nullptr) {
                Utils::printError("Please login to checkout.");
                return;
            }
            
            if (currentCart.checkout()) {
                Utils::printSuccess("Order placed successfully!");
                currentCart.clear();
            } else {
                Utils::printError("Checkout failed.");
            }
            break;
        }
        case 4: {
            currentCart.clear();
            Utils::printSuccess("Cart cleared!");
            break;
        }
        case 5:
            return;
    }
}

void handleUserProfile() {
    Utils::clearScreen();
    Utils::printHeader("User Profile");
    
    currentUser->display();
    
    std::vector<std::string> options = {
        "Edit Profile",
        "Change Password",
        "View Order History",
        "Back to Menu"
    };
    
    int choice = Utils::getMenuChoice(options);
    
    switch (choice) {
        case 1:
            // TODO: Implement edit profile
            Utils::printInfo("Edit profile functionality coming soon!");
            break;
        case 2: {
            std::string newPassword = Utils::getValidString("Enter new password: ");
            currentUser->changePassword(newPassword);
            Utils::printSuccess("Password changed successfully!");
            break;
        }
        case 3:
            // TODO: Implement order history
            Utils::printInfo("Order history functionality coming soon!");
            break;
        case 4:
            return;
    }
}

void handleAdminPanel() {
    Utils::clearScreen();
    Utils::printHeader("Admin Panel");
    
    Admin admin(products, users);
    admin.showAdminMenu();
} 