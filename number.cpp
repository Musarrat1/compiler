#include <iostream>
#include <regex>
#include <string>

using namespace std;

void checkPhoneNumber(const string phoneNumber) {
    // Regular expression for Teletalk numbers
    // Teletalk numbers start with 015 and have 11 digits total
    regex teletalkPattern("^015[0-9]{8}$");
    
    // Regular expression for Grameenphone numbers
    // Grameenphone numbers start with 017, 013, or 019 and have 11 digits total
    regex grameenphonePattern("^01[37][0-9]{8}$");
    
    if (regex_match(phoneNumber, teletalkPattern)) {
        cout << "\n" << phoneNumber << " is a Teletalk number." << endl;
    } else if (regex_match(phoneNumber, grameenphonePattern)) {
        cout << "\n" << phoneNumber << " is a Grameenphone number." << endl;
    } else {
        cout << "\n" << phoneNumber << " is not a recognized Teletalk or Grameenphone number." << endl;
    }
}

int main() {
    cout << "Bangladeshi Mobile Number Identifier" << endl;
    cout << "====================================" << endl;
    cout << "Enter phone numbers to check (enter 'exit' to quit):" << endl;
    
    string userInput;
    while (true) {
        cout << "\nEnter a phone number: ";
        cin >> userInput;
        
        // Exit condition
        if (userInput == "exit" || userInput == "Exit" || userInput == "EXIT") {
            break;
        }
        
        // Check if input contains only digits
        bool validInput = true;
        for (char c : userInput) {
            if (!isdigit(c)) {
                validInput = false;
                break;
            }
        }
        
        if (!validInput) {
            cout << "Invalid input! Please enter only digits." << endl;
            continue;
        }
        
        checkPhoneNumber(userInput);
    }
    
    cout << "\nProgram exited. Thank you!" << endl;
    return 0;
}