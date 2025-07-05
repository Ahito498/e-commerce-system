#ifndef ADMIN_H
#define ADMIN_H
#include <vector>
#include "..//Product/Product.h"
namespace AdminSession {

    // Entry point for the admin session menu
    void run();

    // Core admin features (exposed for testability or use in other modules)
    void addProduct();
    void removeProduct();
    void restockProduct();
    void changeProductPrice();
    void applyDiscount();
    void removeExpiredProducts();
    void viewComplaints();
    void viewAllProducts();
    const std::vector<std::unique_ptr<Product>>& getProductList();

}

#endif
