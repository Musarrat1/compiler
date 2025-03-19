#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

struct Toc {
    string result, operand1, op, operand2;
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

vector<Toc> generatetac(vector<string> postfix, string lhs) {
    stack<string> tempStack;
    vector<Toc> taccode;
    int cnt = 1;
    for (string token : postfix) {
        if (isalnum(token[0])) {
            tempStack.push(token);
        } else {
            string op2 = tempStack.top(); tempStack.pop();
            string op1 = tempStack.top(); tempStack.pop();
            string tempVar = "t" + to_string(cnt++);
            taccode.push_back({tempVar, op1, token, op2});
            tempStack.push(tempVar);
        }
    }
    if (!tempStack.empty()) {
        taccode.push_back({lhs, tempStack.top(), "", ""});
    }
    return taccode;
}

vector<string> tokenize(string expr) {
    vector<string> tokens;
    stringstream str(expr);
    string token;
    while (str >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> InfixToPostfix(vector<string> rhsTokens) {
    vector<string> output;
    stack<string> opstack;
    for (string token : rhsTokens) {
        if (isalnum(token[0])) {
            output.push_back(token);
        } else {
            while (!opstack.empty() && precedence(opstack.top()[0]) >= precedence(token[0])) {
                output.push_back(opstack.top());
                opstack.pop();
            }
            opstack.push(token);
        }
    }
    while (!opstack.empty()) {
        output.push_back(opstack.top());
        opstack.pop();
    }
    return output;
}

int main() {
    string line;
    getline(cin, line);
    vector<string> tokens = tokenize(line);
    if (tokens.size() < 3 || tokens[1] != "=") {
        cout << "Invalid input format. Expected 'lhs = rhs'" << endl;
        return 1;
    }
    string lhs = tokens[0];
    vector<string> rhsTokens(tokens.begin() + 2, tokens.end());
    vector<string> postfix = InfixToPostfix(rhsTokens);
    vector<Toc> taccode = generatetac(postfix, lhs);

    cout << "Generated TAC code:" << endl;
    for (auto line : taccode) {
        if (!line.op.empty()) {
            cout << line.result << " = " << line.operand1 << " " << line.op << " " << line.operand2 << endl;
        } else {
            cout << line.result << " = " << line.operand1 << endl;
        }
    }
    return 0;
}