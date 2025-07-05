#include <iostream>
#include <string>
#include <vector>

// Forward declarations for future implementation
class Admin;
class Customer;
class Cart;
class Product;

// Global variables (will be replaced with proper classes later)
bool isLoggedIn = false;
bool isAdmin = false;
std::string currentUser = "";

// Simple menu functions (placeholder implementations)
void showMainMenu() {
    std::cout << "\n=== E-Commerce System ===\n";
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "3. Browse Products (Guest)\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void showAdminMenu() {
    std::cout << "\n=== Admin Panel ===\n";
    std::cout << "1. Manage Products\n";
    std::cout << "2. View Complaints\n";
    std::cout << "3. View Orders\n";
    std::cout << "4. Logout\n";
    std::cout << "Enter your choice: ";
}

void showCustomerMenu() {
    std::cout << "\n=== Customer Menu ===\n";
    std::cout << "1. Browse Products\n";
    std::cout << "2. View Cart\n";
    std::cout << "3. Order History\n";
    std::cout << "4. Logout\n";
    std::cout << "Enter your choice: ";
}

void handleLogin() {
    std::cout << "\n=== Login ===\n";
    std::string username, password;
    
    std::cout << "Username: ";
    std::cin >> username;
    
    std::cout << "Password: ";
    std::cin >> password;
    
    // Simple validation (will be replaced with proper authentication)
    if (username == "admin" && password == "admin123") {
        isLoggedIn = true;
        isAdmin = true;
        currentUser = username;
        std::cout << "Admin login successful!\n";
    } else if (username == "ahmed123" && password == "pass123") {
        isLoggedIn = true;
        isAdmin = false;
        currentUser = username;
        std::cout << "Customer login successful!\n";
    } else {
        std::cout << "Invalid credentials!\n";
    }
}

void handleRegistration() {
    std::cout << "\n=== Registration ===\n";
    std::cout << "Registration functionality coming soon!\n";
}

void browseProducts() {
    std::cout << "\n=== Product Catalog ===\n";
    std::cout << "1. Power Bank - $350 (Shippable)\n";
    std::cout << "2. Vodafone Recharge 50EGP - $50 (Digital)\n";
    std::cout << "Product browsing functionality coming soon!\n";
}

void manageProducts() {
    std::cout << "\n=== Product Management ===\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Remove Product\n";
    std::cout << "3. Update Stock\n";
    std::cout << "Product management functionality coming soon!\n";
}

void viewComplaints() {
    std::cout << "\n=== Complaints ===\n";
    std::cout << "ahmed123: Late product delivery.\n";
    std::cout << "sara_hasan: Item arrived expired.\n";
}

void viewOrders() {
    std::cout << "\n=== Orders ===\n";
    std::cout << "No orders yet.\n";
}

void viewCart() {
    std::cout << "\n=== Shopping Cart ===\n";
    std::cout << "Cart functionality coming soon!\n";
}

void orderHistory() {
    std::cout << "\n=== Order History ===\n";
    std::cout << "Order history functionality coming soon!\n";
}

int main() {
    std::cout << "Welcome to E-Commerce System!\n";
    std::cout << "Loading data...\n";
    
    bool running = true;
    while (running) {
        if (!isLoggedIn) {
            showMainMenu();
            int choice;
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    handleLogin();
                    break;
                case 2:
                    handleRegistration();
                    break;
                case 3:
                    browseProducts();
                    break;
                case 4:
                    running = false;
                    break;
                default:
                    std::cout << "Invalid choice!\n";
            }
        } else if (isAdmin) {
            showAdminMenu();
            int choice;
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    manageProducts();
                    break;
                case 2:
                    viewComplaints();
                    break;
                case 3:
                    viewOrders();
                    break;
                case 4:
                    isLoggedIn = false;
                    isAdmin = false;
                    currentUser = "";
                    std::cout << "Logged out successfully!\n";
                    break;
                default:
                    std::cout << "Invalid choice!\n";
            }
        } else {
            showCustomerMenu();
            int choice;
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    browseProducts();
                    break;
                case 2:
                    viewCart();
                    break;
                case 3:
                    orderHistory();
                    break;
                case 4:
                    isLoggedIn = false;
                    isAdmin = false;
                    currentUser = "";
                    std::cout << "Logged out successfully!\n";
                    break;
                default:
                    std::cout << "Invalid choice!\n";
            }
        }
    }
    
    std::cout << "Thank you for using E-Commerce System!\n";
    return 0;
}
