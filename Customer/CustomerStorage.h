#ifndef CUSTOMER_STORAGE_H
#define CUSTOMER_STORAGE_H

#include "Customer.h"
#include <vector>

namespace CustomerStorage {
    void saveToFile(const string& filename, const vector<Customer>& list);
    vector<Customer> loadFromFile(const string& filename);
    int findCustomerIndex(const vector<Customer>& list, const string& username);

}

#endif
