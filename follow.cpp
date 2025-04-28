#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX = 10;
char productions[MAX][10]; 
int numProductions;
char firstResult[26][20];  
char followResult[26][20];
bool followDone[26] = {false};


bool isAlreadyIn(char result[], char ch) {
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] == ch)
            return true;
    }
    return false;
}

void addToResult(char result[], char ch) {
    if (!isAlreadyIn(result, ch)) {
        int len = strlen(result);
        result[len] = ch;
        result[len + 1] = '\0';
    }
}

// ---------- FIRST ----------
void findFirst(char result[], char symbol) {
    if (!isupper(symbol)) {
        addToResult(result, symbol);
        return;
    }

    for (int i = 0; i < numProductions; i++) {
        if (productions[i][0] == symbol) {
            int j = 2;
            bool epsilonChain = true;

            while (productions[i][j] != '\0' && epsilonChain) {
                char nextSymbol = productions[i][j];

                if (!isupper(nextSymbol)) {
                    addToResult(result, nextSymbol);
                    epsilonChain = false;
                } else {
                    char temp[20] = "";
                    findFirst(temp, nextSymbol);

                    bool hasEpsilon = false;
                    for (int k = 0; temp[k] != '\0'; k++) {
                        if (temp[k] == '#') hasEpsilon = true;
                        else addToResult(result, temp[k]);
                    }

                    if (!hasEpsilon)
                        epsilonChain = false;
                }
                j++;
            }

            if (epsilonChain) {
                addToResult(result, '#');
            }
        }
    }
}

// ---------- FOLLOW ----------
void findFollow(char symbol) {
    int index = symbol - 'A';

    if (followDone[index]) return;
    followDone[index] = true;

    if (symbol == productions[0][0]) {
        addToResult(followResult[index], '$');
    }

    for (int i = 0; i < numProductions; i++) {
        char *prod = productions[i];
        int len = strlen(prod);

        for (int j = 2; j < len; j++) {
            if (prod[j] == symbol) {
                bool followed = false;

                int k = j + 1;
                while (k < len && !followed) {
                    char next = prod[k];

                    if (!isupper(next)) {
                        addToResult(followResult[index], next);
                        followed = true;
                    } else {
                        char temp[20] = "";
                        findFirst(temp, next);

                        bool hasEpsilon = false;
                        for (int m = 0; temp[m] != '\0'; m++) {
                            if (temp[m] == '#')
                                hasEpsilon = true;
                            else
                                addToResult(followResult[index], temp[m]);
                        }

                        if (!hasEpsilon) {
                            followed = true;
                        } else {
                            k++;
                        }
                    }
                }

                // If end of production or everything to the right is null
                if (k >= len) {
                    if (prod[0] != symbol) {
                        findFollow(prod[0]);
                        int lhsIndex = prod[0] - 'A';
                        for (int m = 0; followResult[lhsIndex][m] != '\0'; m++) {
                            addToResult(followResult[index], followResult[lhsIndex][m]);
                        }
                    }
                }
            }
        }
    }
}


int main() {
    char choice;
    char result[20];

    cout << "Enter number of productions: ";
    cin >> numProductions;

    cout << "Enter productions (Ex: E=E+T):\n";
    for (int i = 0; i < numProductions; i++) {
        cin >> productions[i];
    }

    for (int i = 0; i < numProductions; i++) {
        char nonTerminal = productions[i][0];
        int index = nonTerminal - 'A';
        firstResult[index][0] = '\0';
        findFirst(firstResult[index], nonTerminal);
    }

    for (int i = 0; i < numProductions; i++) {
        char nonTerminal = productions[i][0];
        findFollow(nonTerminal);
    }

    while (true) {
        char inputSymbol;
        cout << "\nEnter a symbol to find FIRST and FOLLOW: ";
        cin >> inputSymbol;

        int index = inputSymbol - 'A';

        cout << "FIRST(" << inputSymbol << ") = { ";
        for (int i = 0; firstResult[index][i] != '\0'; i++)
            cout << firstResult[index][i] << " ";
        cout << "}\n";

        cout << "FOLLOW(" << inputSymbol << ") = { ";
        for (int i = 0; followResult[index][i] != '\0'; i++)
            cout << followResult[index][i] << " ";
        cout << "}\n";

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y')
            break;
    }

    return 0;
}