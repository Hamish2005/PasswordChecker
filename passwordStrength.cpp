#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool hasUppercase(const string& password) {
    for (char ch : password) {
        if (isupper(ch)) return true;
    }
    return false;
}

bool hasLowercase(const string& password) {
    for (char ch : password) {
        if (islower(ch)) return true;
    }
    return false;
}

bool hasDigit(const string& password) {
    for (char ch : password) {
        if (isdigit(ch)) return true;
    }
    return false;
}

bool hasSpecialChar(const string& password) {
    string specialChars = "!@#$%^&*()-_+=<>?/|";
    for (char ch : password) {
        if (specialChars.find(ch) != string::npos) return true;
    }
    return false;
}

void evaluatePassword(const string& password) {
    cout << "Evaluating password strength...\n";

    bool lengthCriteria = password.length() >= 8;
    bool uppercase = hasUppercase(password);
    bool lowercase = hasLowercase(password);
    bool digit = hasDigit(password);
    bool specialChar = hasSpecialChar(password);

    if (lengthCriteria && uppercase && lowercase && digit && specialChar) {
        cout << "Your password is strong!\n";
    } else {
        cout << "Your password is weak. Suggestions to improve:\n";
        if (!lengthCriteria) cout << "- Make the password at least 8 characters long.\n";
        if (!uppercase) cout << "- Include at least one uppercase letter.\n";
        if (!lowercase) cout << "- Include at least one lowercase letter.\n";
        if (!digit) cout << "- Include at least one digit.\n";
        if (!specialChar) cout << "- Include at least one special character (!, @, #, etc.).\n";
    }
}

int main() {
    string password;

    cout << "Enter a password to check its strength: ";
    getline(cin, password);

    evaluatePassword(password);

    return 0;
}
