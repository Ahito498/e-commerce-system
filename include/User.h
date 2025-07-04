#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
private:
    int id;
    std::string username;
    std::string password;
    std::string email;
    std::string fullName;
    std::string phone;
    std::string address;
    bool isAdmin;
    bool isActive;

public:
    // Constructors
    User();
    User(int id, const std::string& username, const std::string& password,
         const std::string& email, const std::string& fullName);
    
    // Getters
    int getId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;
    std::string getFullName() const;
    std::string getPhone() const;
    std::string getAddress() const;
    bool getIsAdmin() const;
    bool getIsActive() const;
    
    // Setters
    void setId(int id);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setEmail(const std::string& email);
    void setFullName(const std::string& fullName);
    void setPhone(const std::string& phone);
    void setAddress(const std::string& address);
    void setIsAdmin(bool isAdmin);
    void setIsActive(bool isActive);
    
    // Authentication methods
    bool authenticate(const std::string& inputPassword) const;
    void changePassword(const std::string& newPassword);
    
    // Utility methods
    void display() const;
    void displayShort() const;
    bool isValidEmail() const;
    bool isValidPhone() const;
    
    // File I/O methods
    std::string toFileString() const;
    static User fromFileString(const std::string& line);
    
    // Operator overloads
    bool operator==(const User& other) const;
    bool operator<(const User& other) const;
};

#endif // USER_H 