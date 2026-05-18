// Blake Turman
#include "UserInputHandling.hpp"

// public

std::string UserInputHandling::input = "";

int UserInputHandling::getInt() {
    bool valid = false;
    int value = 0;

    while (!valid) {

        getInput();

        if (detectChar()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stoi(input);
                valid = true;
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
        
    
}

int UserInputHandling::getInt(const int& min, const int& max) {
    bool valid = false;
    int value = 0;

    while (!valid) {

        getInput();

        if (detectChar()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stoi(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
        
    
}

long long UserInputHandling::getLongLong() {
    bool valid = false;
    long long value = 0;

    while (!valid) {

        getInput();

        if (detectChar()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stoll(input);
                valid = true;
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
        
    
}

long long UserInputHandling::getLongLong(const long long& min, const long long& max) {
    bool valid = false;
    long long value = 0;

    while (!valid) {

        getInput();

        if (detectChar()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stoll(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
        
    
}

unsigned long long UserInputHandling::getUnsignedLongLong() {
    bool valid = false;
    unsigned long long value = 0;

    while (!valid) {

        getInput();

        if (detectCharUnsigned()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stoull(input);
                valid = true;
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
        
    
}

unsigned long long UserInputHandling::getUnsignedLongLong(const unsigned long long& min, const unsigned long long& max) {
    bool valid = false;
    unsigned long long value = 0;

    while (!valid) {

        getInput();

        if (detectCharUnsigned()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stoull(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
        
    
}

double UserInputHandling::getDouble() {
    bool valid = false;
    double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stod(input);
                valid = true;
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

double UserInputHandling::getDouble(const double& min, const double& max) {
    bool valid = false;
    double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stod(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

double UserInputHandling::getDouble(const unsigned& decimalPlaces) {
    bool valid = false;
    double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else if (!checkDecimalPlaces(decimalPlaces)) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stod(input);
                
                valid = true;
                
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

double UserInputHandling::getDouble(const double& min, const double& max, const unsigned& decimalPlaces) {
    bool valid = false;
    double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else if (!checkDecimalPlaces(decimalPlaces)) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {


            try {
                value = std::stod(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

long double UserInputHandling::getLongDouble() {
    bool valid = false;
    long double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stold(input);
                valid = true;
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

long double UserInputHandling::getLongDouble(const long double& min, const long double& max) {
    bool valid = false;
    long double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stold(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

long double UserInputHandling::getLongDouble(unsigned& decimalPlaces) {
    bool valid = false;
    long double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else if (!checkDecimalPlaces(decimalPlaces)) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            try {
                value = std::stold(input); 
                valid = true;  
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

long double UserInputHandling::getLongDouble(const long double& min, const long double& max, const unsigned& decimalPlaces) {
    bool valid = false;
    long double value = 0;

    while (!valid) {

        getInput();

        if (detectCharFloat()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else if (!checkDecimalPlaces(decimalPlaces)) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {


            try {
                value = std::stold(input);
                if (value < min || value > max) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                else {
                    valid = true;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        }

    return value;
}

char UserInputHandling::getChar() {
    bool valid = false;
    char value = '\0';

    while (!valid) {

        getInput();

        if (input.length() != 1) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            value = input[0];
            valid = true;
        }
    }

    return value;
}


char UserInputHandling::getChar(const char* const& validChars, const size_t& size) {
    bool valid = false;
    char value = '\0';

    while (!valid) {

        getInput();

        if (input.length() != 1) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            value = input[0];
            
            for (size_t i = 0; i < size && !valid; ++i)  {
                if (value == validChars[i]) {
                    valid = true;
                }
            }
        }
    }

    return value;
}

std::string UserInputHandling::getString() {
    std::string value = "";

    getInput();

    value = input;

    return value;
}

std::string UserInputHandling::getString(const std::string* const& validStrings, const size_t& size) {
    bool valid = false;
    std::string value = "";

    while (!valid) {

        getInput();

        value = input;
            
        for (size_t i = 0; i < size && !valid; ++i)  {
            if (value == validStrings[i]) {
                valid = true;
            }
        }

        if (!valid) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return value;
}

std::string UserInputHandling::getString(const char* const& invalidChars, const size_t& size) {
    bool valid = false;
    std::string value = "";

    while (!valid) {
        valid = true;

        getInput();

        value = input;

        for (size_t i = 0; i < value.length() && valid; ++i) {
            for (size_t j = 0; j < size && valid; ++j) {
                if (value[i] == invalidChars[j]) {
                    valid = false;
                }
            }
        }

        if (!valid) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return value;
}

std::string UserInputHandling::getString(const size_t& maxLength) {
    bool valid = false;
    std::string value = "";

    while (!valid) {

        getInput();

        value = input;

        if (input.length() > maxLength) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            valid = true;
        }

    }

    return value;
}

std::string UserInputHandling::getString(const char* const& invalidChars, const size_t& size, const size_t& maxLength) {
    bool valid = false;
    std::string value = "";

    while (!valid) {
        valid = true;

        getInput();

        value = input;

        if (value.length() > maxLength) {
            valid = false;
        }

        for (size_t i = 0; i < value.length() && valid; ++i) {
            for (size_t j = 0; j < size && valid; ++j) {
                if (value[i] == invalidChars[j]) {
                    valid = false;
                }
            }
        }

        if (!valid) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return value;
}

std::string UserInputHandling::getStringAlpha() {
    bool valid = false;
    std::string value = "";

    while (!valid) {
        valid = true;

        getInput();

        value = input;

        for (size_t i = 0; i < value.length() && valid; ++i) {
            if (!isalpha(value[i])) {
                valid = false;
            }
        }

        if (!valid) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }

    }

    return value;
}

std::string UserInputHandling::getStringAlpha(const size_t& maxLength) {
    bool valid = false;
    std::string value = "";

    while (!valid) {

        getInput();

        value = input;

        if (input.length() <= maxLength) {
            valid = true;
        }

        for (size_t i = 0; i < value.length() && valid; ++i) {
            if (!isalpha(value[i])) {
                valid = false;
            }
        }

        if (!valid) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }

    }

    return value;
}

// private

void UserInputHandling::getInput() {
    input.clear();

    while (input.empty()) {
        
        std::getline(std::cin, input);

        input.erase(0, input.find_first_not_of(" \t\r\n"));
        input.erase(input.find_last_not_of(" \t\r\n") + 1);
    }
}

bool UserInputHandling::checkDecimalPlaces(const unsigned& decimalPlaces) {
    bool valid = true,
    foundDecimal = false;
    unsigned decimalPlacesCount = 0;

    for (size_t i = 0; i < input.length() && valid; ++i) {
        if (foundDecimal) {
            ++decimalPlacesCount;
            if (decimalPlacesCount > decimalPlaces)
            {
                valid = false;
            }
        }
        if (input[i] == '.') {
            foundDecimal = true;
        }
        
    }

    return valid;
}

bool UserInputHandling::detectChar() {
    bool charFlag = false;

    if (input[0] != '-' && !std::isdigit(input[0])) {
        charFlag = true;
    }
    else {

        for (size_t i = 1; i < input.length() && !charFlag; ++i) {
            if (!std::isdigit(input[i])) {
            
                charFlag = true;
            }
        }
    }

    return charFlag;
}

bool UserInputHandling::detectCharUnsigned() {
    bool charFlag = false;

    for (size_t i = 0; i < input.length() && !charFlag; ++i) {
        if (!std::isdigit(input[i])) {
         
            charFlag = true;
        }
    }

    return charFlag;
}

bool UserInputHandling::detectCharFloat() {
    bool charFlag = false;
    unsigned decimalCount = 0;

    if (input[0] != '-' && input[0] != '.' && !std::isdigit(input[0])) {
        charFlag = true;
    }
    else {

        for (size_t i = 1; i < input.length() && !charFlag; ++i) {
            if (!std::isdigit(input[i])) {
                if (input[i] == '.' && decimalCount == 0) {
                    ++decimalCount;
                }
                else {
                    charFlag = true;
                }
            
            }
        }
    }

    return charFlag;
}

bool UserInputHandling::detectCharFloatUnsigned() {
    bool charFlag = false;
    unsigned decimalCount = 0;

    for (size_t i = 0; i < input.length() && !charFlag; ++i) {

        if (!std::isdigit(input[i])) {
            if (input[i] == '.' && decimalCount == 0) {
                ++decimalCount;
            }
            else {
                charFlag = true;
            }
           
        }
            
    }

    return charFlag;
}
