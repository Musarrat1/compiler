#include<iostream>
#include<vector>
#include<string>
using namespace std;
int precedence(char op){
    
    if(op=='+'|| op == '-')return 1;
    if(op=='*'|| op=='/')return 2;
    return 0;
}
vector<string> tokenize(string expr){
    vector<string> tokens ;
    stringstream str(expr);
    string token;
    while(str>>token){
        tokens.push_back(token);

    }
}
vector<string>InfixToPostfix( vector<string>rhsTokens){
    vector<string> output;
    vector<string>opstack;
    for(string token : rhsTokens){
        if(isalnum(token[0])){
            output.push_back(token);
        }
        else{
            while(!opstack.empty() && precedence(opstack.top()[0])>=precedence(token[0])){
                output.push_back(opstack.top());
                opstack.pop();

            }
        }
    }


}
int main(){
    string line;
    getline(cin,line);
    vector<string> tokens= tokenize(line);
    string lhs = tokens[0];
    vector<string>rhsTokens(tokens.begin()+2,tokens.end());
    vector<string> postfix = InfixToPostfix(rhsTokens);

}