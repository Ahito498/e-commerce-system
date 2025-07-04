#ifndef ADMIN_H
#define ADMIN_H

#include "Product.h"
#include "User.h"
#include <vector>
#include <string>

class Admin {
private:
    std::vector<Product>& products;
    std::vector<User>& users;
    int nextProductId;
    int nextUserId;

public:
    // Constructor
    Admin(std::vector<Product>& products, std::vector<User>& users);
    
    // Product Management
    bool addProduct(const std::string& name, const std::string& description,
                   const std::string& category, double price, int stockQuantity);
    bool editProduct(int productId, const std::string& name, const std::string& description,
                    const std::string& category, double price, int stockQuantity);
    bool deleteProduct(int productId);
    bool updateProductStock(int productId, int newQuantity);
    Product* findProduct(int productId);
    std::vector<Product> searchProducts(const std::string& query);
    std::vector<Product> getProductsByCategory(const std::string& category);
    
    // User Management
    bool addUser(const std::string& username, const std::string& password,
                const std::string& email, const std::string& fullName, bool isAdmin = false);
    bool editUser(int userId, const std::string& username, const std::string& email,
                 const std::string& fullName, const std::string& phone, const std::string& address);
    bool deleteUser(int userId);
    bool deactivateUser(int userId);
    bool activateUser(int userId);
    User* findUser(int userId);
    User* findUserByUsername(const std::string& username);
    std::vector<User> searchUsers(const std::string& query);
    
    // Reports and Analytics
    void displayProductReport() const;
    void displayUserReport() const;
    void displaySalesReport() const;
    void displayLowStockProducts() const;
    void displayTopProducts() const;
    
    // Utility methods
    int getNextProductId();
    int getNextUserId();
    void saveData();
    void loadData();
    
    // Admin menu
    void showAdminMenu();
    void handleProductManagement();
    void handleUserManagement();
    void handleReports();
};

#endif // ADMIN_H 