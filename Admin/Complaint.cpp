#include "Complaint.h"
#include <fstream>
#include <iostream>

using namespace std;

Complaint::Complaint(string name, string date, string message)
    : customerName(name), date(date), message(message) {}

void Complaint::print() const {
    cout << "-------------------------" << endl;
    cout << "From: " << customerName << endl;
    cout << "Date: " << date << endl;
    cout << "Message: " << message << endl;
}

vector<Complaint> Complaint::loadFromFile(const string& filename) {
    vector<Complaint> complaints;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open complaints file." << endl;
        return complaints;
    }

    string name, date, message;

    while (getline(file, name)) {
        if (!getline(file, date)) break;
        if (!getline(file, message)) break;

        complaints.emplace_back(name, date, message);
    }

    file.close();
    return complaints;
}
