#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <vector>
#include <limits>

namespace Utils {
    // Input validation
    int getValidInt(const std::string& prompt, int min = std::numeric_limits<int>::min(), 
                   int max = std::numeric_limits<int>::max());
    double getValidDouble(const std::string& prompt, double min = std::numeric_limits<double>::min(), 
                         double max = std::numeric_limits<double>::max());
    std::string getValidString(const std::string& prompt, size_t minLength = 1, size_t maxLength = 100);
    std::string getValidEmail(const std::string& prompt);
    std::string getValidPhone(const std::string& prompt);
    
    // String utilities
    std::string toLowerCase(const std::string& str);
    std::string toUpperCase(const std::string& str);
    std::string trim(const std::string& str);
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::string join(const std::vector<std::string>& vec, const std::string& delimiter);
    bool startsWith(const std::string& str, const std::string& prefix);
    bool endsWith(const std::string& str, const std::string& suffix);
    bool contains(const std::string& str, const std::string& substr);
    
    // UI utilities
    void clearScreen();
    void printHeader(const std::string& title);
    void printSeparator(char separator = '-', int length = 50);
    void printMenu(const std::vector<std::string>& options);
    int getMenuChoice(const std::vector<std::string>& options);
    void printSuccess(const std::string& message);
    void printError(const std::string& message);
    void printWarning(const std::string& message);
    void printInfo(const std::string& message);
    
    // File utilities
    bool fileExists(const std::string& filename);
    bool createDirectory(const std::string& path);
    std::vector<std::string> readFileLines(const std::string& filename);
    bool writeFileLines(const std::string& filename, const std::vector<std::string>& lines);
    
    // Validation utilities
    bool isValidEmail(const std::string& email);
    bool isValidPhone(const std::string& phone);
    bool isValidPrice(double price);
    bool isValidQuantity(int quantity);
    bool isValidId(int id);
    
    // Formatting utilities
    std::string formatPrice(double price);
    std::string formatDate(const std::string& date);
    std::string formatTime(const std::string& time);
    std::string centerText(const std::string& text, int width);
    std::string leftAlign(const std::string& text, int width);
    std::string rightAlign(const std::string& text, int width);
    
    // Random utilities
    int generateRandomId();
    std::string generateRandomString(int length);
    double generateRandomPrice(double min, double max);
}

#endif // UTILS_H 