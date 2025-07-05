#include "CustomerStorage.h"
#include <fstream>
#include <iostream>

using namespace std;

void CustomerStorage::saveToFile(const string& filename, const vector<Customer>& list) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open customer file for writing." << endl;
        return;
    }

    for (size_t i = 0; i < list.size(); ++i) {
        file << list[i].getUsername() << endl;
        file << list[i].checkPassword("") << endl;
        file << list[i].getBalance() << endl;
    }

    file.close();
}

vector<Customer> CustomerStorage::loadFromFile(const string& filename) {
    vector<Customer> list;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Customer file not found." << endl;
        return list;
    }

    string username;
    string password;
    string balanceStr;

    while (getline(file, username) &&
           getline(file, password) &&
           getline(file, balanceStr)) {
        double balance = stod(balanceStr);
        list.push_back(Customer(username, password, balance));
           }

    file.close();
    return list;
}


int CustomerStorage::findCustomerIndex(const vector<Customer>& list, const string& name) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i].getUsername() == name) return static_cast<int>(i);
    }
    return -1;
}
