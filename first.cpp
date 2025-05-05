#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
char production[MAX][10];
int numProduction;

bool isAlreadyIn(char result[], char ch) {
    for(int i = 0; result[i] != '\0'; i++) {
        if(result[i] == ch)
            return true;
    }
    return false;
}

void addToResult(char result[], char ch) {
    if(!isAlreadyIn(result, ch)) {
        int len = strlen(result);
        result[len] = ch;
        result[len + 1] = '\0';
    }
}

void findFirst(char result[], char symbol) {
    if(!isupper(symbol)) {
        addToResult(result, symbol);
        return;
    }
    
    for(int i = 0; i < numProduction; i++) {
        if(production[i][0] == symbol) {
            char nextSymbol = production[i][2];
            
            if(nextSymbol == '#') {
                addToResult(result, '#');
            }
            else if(!isupper(nextSymbol)) {
                addToResult(result, nextSymbol);
            }
            else {
                findFirst(result, nextSymbol);
            }
        }
    }
}

int main() {
    char result[20], choice, inputSymbol;
    
    cout << "Enter number of production: ";
    cin >> numProduction;
    
    cout << "Enter the expressions: ";
    for(int i = 0; i < numProduction; i++) {
        cin >> production[i];
    }
    
    while(true) {
        cout << "Find FIRST of which symbol? ";
        cin >> inputSymbol;
        
        result[0] = '\0';
        findFirst(result, inputSymbol);
        
        cout << "FIRST(" << inputSymbol << ") = { ";
        for(int i = 0; result[i] != '\0'; i++) {
            cout << result[i] << " ";
        }
        cout << "}" << endl;
        
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        
        if(choice != 'y' && choice != 'Y') {
            break;
        }
    }
    
    return 0;
}