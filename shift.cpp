#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> parseStack;

void printStack() {
    cout << "\n\t\t\t $";
    stack<char> temp = parseStack;
    string output = "";
    while (!temp.empty()) {
        output = temp.top() + output;
        temp.pop();
    }
    cout << output;
}

int main() {
    string input;
    cout << "\n\n\t\t LR PARSING";
    cout << "\n\t\t ENTER THE EXPRESSION: ";
    cin >> input;

    cout << "\n\t\t $";
    size_t i = 0;

    //  shift operations
    while (i < input.length()) {
        if (input[i] == 'i' && i + 1 < input.length() && input[i + 1] == 'd') {
            printStack();
            cout << " id";           // shift id
            parseStack.push('E');    // reduce id to E
            i += 2;
            printStack();
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            parseStack.push(input[i]);
            i++;
            printStack();
        } else {
            cout << "\n\t\tInvalid character encountered: " << input[i] << endl;
            return 1;
        }
    }

    // reduce operations
    while (!parseStack.empty()) {
        char op = parseStack.top(); parseStack.pop();

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            if (!parseStack.empty() && parseStack.top() == 'E') {
                parseStack.pop(); // pop E after operator
                parseStack.push('E'); // reduce E op E to E
                printStack();
            } else {
                cout << "\n\t\tError: Expected 'E' after operator.\n";
                return 1;
            }
        } else if (op == 'E') {
            printStack();
        } else {
            cout << "\n\t\tError: Unexpected symbol in stack: " << op << endl;
            return 1;
        }
    }

    cout << "\n\n\t\tParsing complete.\n";
    return 0;
}
