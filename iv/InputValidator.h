#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>
using namespace std;
namespace InputValidator {
    int getValidatedInt(int min, int max);      //validate the input range to avoid crashing the program
    double getValidatedDouble(double min);      //same for double
    string getNonEmptyString();                 //make sure that the input string is not empty
}

#endif
