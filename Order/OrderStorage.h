#ifndef ORDER_STORAGE_H
#define ORDER_STORAGE_H

#include "../Customer/CartItem.h"
#include <vector>
#include <string>

namespace OrderStorage {
    void saveOrder(const std::string& filename, const std::string& customerUsername, const std::vector<CartItem>& items, double shipping, double total);
}

#endif
