#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    bool isAlphanumeric = true;

    cout << "Enter a string: ";
    getline(cin, input);


    for (int i = 0; i < input.length(); i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') ||
               (input[i] >= 'A' && input[i] <= 'Z') ||
               (input[i] >= '0' && input[i] <= '9'))) {
            isAlphanumeric = false;
            break;
        }
    }


    if (isAlphanumeric)
        cout << "The string is alphanumeric." << endl;
    else
        cout << "The string is not alphanumeric." << endl;

    return 0;
}
