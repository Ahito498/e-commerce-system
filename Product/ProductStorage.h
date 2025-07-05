#ifndef PRODUCT_STORAGE_H
#define PRODUCT_STORAGE_H

#include "Product.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

namespace ProductStorage {
    void saveToFile(const string& filename, const vector<unique_ptr<Product>>& list);
    vector<unique_ptr<Product>> loadFromFile(const string& filename);
}

#endif
