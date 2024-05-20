#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random password
std::string generatePassword(int length, bool includeUppercase, bool includeLowercase, bool includeDigits, bool includeSpecial) {
    std::string password;
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string digits = "0123456789";
    std::string special = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/\\`~";
    std::string allCharacters;

    if (includeUppercase) {
        allCharacters += uppercase;
    }
    if (includeLowercase) {
        allCharacters += lowercase;
    }
    if (includeDigits) {
        allCharacters += digits;
    }
    if (includeSpecial) {
        allCharacters += special;
    }

    if (allCharacters.empty()) {
        std::cerr << "Error: No character sets selected!" << std::endl;
        return "";
    }

    std::srand(std::time(nullptr)); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        password += allCharacters[std::rand() % allCharacters.size()];
    }

    return password;
}

int main() {
    int length;
    char includeUppercase, includeLowercase, includeDigits, includeSpecial;

    std::cout << "Enter the desired password length: ";
    std::cin >> length;
    std::cout << "Include uppercase letters? (y/n): ";
    std::cin >> includeUppercase;
    std::cout << "Include lowercase letters? (y/n): ";
    std::cin >> includeLowercase;
    std::cout << "Include digits? (y/n): ";
    std::cin >> includeDigits;
    std::cout << "Include special characters? (y/n): ";
    std::cin >> includeSpecial;

    std::string password = generatePassword(
        length,
        includeUppercase == 'y' || includeUppercase == 'Y',
        includeLowercase == 'y' || includeLowercase == 'Y',
        includeDigits == 'y' || includeDigits == 'Y',
        includeSpecial == 'y' || includeSpecial == 'Y'
    );

    if (!password.empty()) {
        std::cout << "Generated Password: " << password << std::endl;
    }

    return 0;
}
