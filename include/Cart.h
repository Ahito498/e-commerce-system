#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>
#include <map>
#include <string>

struct CartItem {
    Product product;
    int quantity;
    
    CartItem(const Product& p, int qty = 1) : product(p), quantity(qty) {}
};

class Cart {
private:
    std::map<int, CartItem> items; // product_id -> CartItem
    double totalPrice;
    int totalItems;

public:
    // Constructors
    Cart();
    
    // Cart operations
    bool addItem(const Product& product, int quantity = 1);
    bool removeItem(int productId);
    bool updateQuantity(int productId, int newQuantity);
    void clear();
    
    // Getters
    double getTotalPrice() const;
    int getTotalItems() const;
    int getItemCount() const;
    std::vector<CartItem> getItems() const;
    CartItem* getItem(int productId);
    
    // Utility methods
    void display() const;
    void displaySummary() const;
    bool isEmpty() const;
    bool containsProduct(int productId) const;
    
    // Price calculations
    void recalculateTotal();
    double calculateSubtotal() const;
    double calculateTax() const;
    double calculateShipping() const;
    
    // Checkout methods
    bool checkout();
    std::string generateOrderSummary() const;
    
    // File I/O methods
    std::string toFileString() const;
    static Cart fromFileString(const std::string& line);
};

#endif // CART_H 