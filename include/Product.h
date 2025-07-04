#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    std::string description;
    std::string category;
    double price;
    int stockQuantity;
    bool isAvailable;

public:
    // Constructors
    Product();
    Product(int id, const std::string& name, const std::string& description, 
            const std::string& category, double price, int stockQuantity);
    
    // Getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStockQuantity() const;
    bool getIsAvailable() const;
    
    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setCategory(const std::string& category);
    void setPrice(double price);
    void setStockQuantity(int quantity);
    void setIsAvailable(bool available);
    
    // Utility methods
    void display() const;
    void displayShort() const;
    bool updateStock(int quantity);
    bool isInStock() const;
    
    // File I/O methods
    std::string toFileString() const;
    static Product fromFileString(const std::string& line);
    
    // Operator overloads
    bool operator==(const Product& other) const;
    bool operator<(const Product& other) const;
};

#endif // PRODUCT_H 