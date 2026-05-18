// Blake Turman
#ifndef USER_INPUT_HANDLING_HPP
#define USER_INPUT_HANDLING_HPP

#include <iostream>
#include <string>

// Personal utility class for more control over user inputs
class UserInputHandling {
    public:

        // returns validated integer input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        // sends invalid error message to cout when input is invalid
        static int getInt();

        // overload: specify range of valid integers
        static int getInt(const int& min, const int& max);

        // returns validated long long input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        // sends invalid error message to cout when input is invalid
        static long long getLongLong();

        // overload: specify range of valid long longs
        static long long getLongLong(const long long& min, const long long& max);

        // returns validated unsigned long long input from user
        static unsigned long long getUnsignedLongLong();

        // overload: specify range of valid unsigned long longs
        static unsigned long long getUnsignedLongLong(const unsigned long long& min, const unsigned long long& max);

        // returns validated double input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        // sends invalid error message to cout when input is invalid
        // scientific notation is not accepted, e.g. "1.5e2"
        static double getDouble();

        // overload: specify range of valid doubles
        static double getDouble(const double& min, const double& max);

        // overload: specify maximum allowed decimal places
        static double getDouble(const unsigned& decimalPlaces);

        // overload: specify range of valid doubles and maximum allowed decimal places
        static double getDouble(const double& min, const double& max, const unsigned& decimalPlaces);

        // returns validated long double input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        // sends invalid error message to cout when input is invalid
        // scientific notation is not accepted, e.g. "1.5e2"
        static long double getLongDouble();

        // overload: specify range of valid long doubles
        static long double getLongDouble(const long double& min, const long double& max);

        // overload: specify maximum allowed decimal places
        static long double getLongDouble(unsigned& decimalPlaces);

        // overload: specify range of valid long doubles and maximum allowed decimal places
        static long double getLongDouble(const long double& min, const long double& max, const unsigned& decimalPlaces);

        // returns validated char input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        // sends invalid error message to cout when input is invalid
        static char getChar();

        // overload: specify array of valid chars
        static char getChar(const char* const& validChars, const size_t& size);

        // returns validated string input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        static std::string getString();

        // overload: specify array of valid strings
        // sends invalid error message to cout when input is invalid
        static std::string getString(const std::string* const& validStrings, const size_t& size);

        // overload: specify array of invalid characters
        static std::string getString(const char* const& invalidChars, const size_t& size);

        // overload: specify max length
        static std::string getString(const size_t& maxLength);

        // overload: specify array of invalid characters and max length
        static std::string getString(const char* const& invalidChars, const size_t& size, const size_t& maxLength);

        // returns validated alphabetical string input from user
        // loops until valid input is given
        // surrounding whitespace is ignored
        // sends invalid error message to cout when input is invalid
        static std::string getStringAlpha();

        // overload: specify max length
        static std::string getStringAlpha(const size_t& maxLength);


    private:
        static std::string input; // stores temporary user input

        // ensures user inputs non-whitespace non-empty string
        // note: recommended to call clearStream() prior to this function
        static void getInput();

        // returns true if input has less than or equal to specified decimal places
        // precond: function assumes only digits after decimal point
        static bool checkDecimalPlaces(const unsigned& decimalPlaces);

        // returns true if input contains non-digit characters
        // examples: "-1" returns false, "1" returns false, "1a" returns true, "a1" returns true
        //          "1.5" returns true, " 1" returns true, "1 " returns true, "-" returns false
        // precond: input is not empty
        static bool detectChar();

        // returns true if input contains non-digit characters
        // examples: "-1" returns true, "1" returns false, "1a" returns true, "a1" returns true
        //          "1.5" returns true, " 1" returns true, "1 " returns true, "-" returns true
        static bool detectCharUnsigned();

        // returns true if input contains non-digit characters
        // examples: "-1" returns false, "1" returns false, "1a" returns true, "a1" returns true
        //          "1.5" returns false, " 1" returns true, "1 " returns true, "-.5" returns false
        //          ".5" returns false, "5." returns false, "." returns false, "-" returns false
        // precond: input is not empty
        static bool detectCharFloat();

        // returns true if input contains non-digit characters
        // examples: "-1" returns true, "1" returns false, "1a" returns true, "a1" returns true
        //          "1.5" returns false, " 1" returns true, "1 " returns true, "-.5" returns true
        //          ".5" returns false, "5." returns false, "." returns false, "-" returns true
        static bool detectCharFloatUnsigned();
};



#endif