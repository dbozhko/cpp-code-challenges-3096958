// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    std::vector<std::string> parts;
    std::string current_part;
    for (char c : ip) {
        if (c == '.') {
            parts.push_back(current_part);
            current_part.clear();
        } else {
            current_part += c;
        }
    }
    parts.push_back(current_part); // Add the last part
    if (parts.size() != 4) {
        return false; // IP address must have exactly 4 parts
    }

    for (const std::string& part : parts) {
        if (part.empty() || part.length() > 3) {
            return false; // Each part must be non-empty and at most 3 digits
        }
        for (char c : part) {
            if (!isdigit(c)) {
                return false; // Each part must contain only digits
            }
        }
        int value = std::stoi(part);
        if (value < 0 || value > 255) {
            return false; // Each part must be between 0 and 255
        }
        if (part[0] == '0' && part.length() > 1) {
            return false; // No leading zeros allowed
        }
    }

    return true;
}

// Main function
int main(){
    std::string s;

    /*
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    */

    //test cases
    std::vector<std::pair<std::string, bool>> test_cases = {
        {"158.25.0.33", true},
        {"256.100.50.25", false},
        {"192.168.1.1", true},
        {"192.168.001.01", false},
        {"0.0.0.0", true},
        {"01.02.03.04", false},
        {"255.255.255.255", true},
        {"192.168.1", false},
        {"192.168.1.", false},
        {".192.168.1.", false},
        {"a.b.c.d", false},
        {"1", false},
        {"1.2", false},
        {"1.2.3", false},
        {"a1.2.3.4", false},
        {"1.2.3.4a", false},
        {"hello.world.this.is.test", false},
        {"1234.567.89.0", false},
        {"asd;f gjkh",false},
        {"12..34.56", false},
        {"", false}       
    };
    for (const auto& test_case : test_cases) 
    {
        const std::string& ip = test_case.first;
        bool expected = test_case.second;
        bool result = is_valid_ip(ip);
        std::cout << "Test IP: " << ip << " | Expected: " << (expected ? "Valid" : "Invalid") 
                  << " | Result: " << (result ? "Valid" : "Invalid") 
                  << " | " << (result == expected ? "PASS" : "FAIL") << std::endl;
    }
    return 0;
}
