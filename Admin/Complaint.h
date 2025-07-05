#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <string>
#include <vector>

using namespace std;

class Complaint {
private:
    string customerName;
    string date;
    string message;

public:
    Complaint(string name, string date, string message);

    void print() const;

    static vector<Complaint> loadFromFile(const string& filename);
};

#endif
