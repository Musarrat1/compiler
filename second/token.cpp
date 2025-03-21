#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

bool isSeparator(char ch){
    string value = ",;(){}[]";
    for(int i=0; i<value.length(); i++){
        if(ch == value[i]){
            return true;
        }
    }
    return false;
}




bool isOparator(char ch){
    string value = "+-*/<>=!";
    for(int i=0; i<value.length(); i++){
        if(ch == value[i]){
            return true;
        }
    }
    return false;
}

bool isKeyword(string s){
    string keyword[] = {
        "auto", "break", "case", "char", "enum", "const", "continue", "default", "do", "double", "else", "float", "for",
        "goto", "if", "int","return","intlude","main","using","namespace","std"
    };
    for(int i=0; i<(sizeof(keyword)/sizeof(string)); i++){
        if(s == keyword[i])
            return true;
    }
    return false;
}

bool isIdentifier(string s){
    if(isKeyword(s))
        return false;
    if(s.empty() || (s[0] >= '0' && s[0] <= '9'))
        return false;
    for(int i=0; i<s.length(); i++){
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            return false;
    }
    return true;
}

bool isNumber(string s){
    if(s.empty())
        return false;
    for(int i=0; i<s.length(); i++){
        if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
            return false;
    }
    return true;
}

void parse(string s){
    vector<string> tokens;
    string token = "";
    for(int i=0; i<s.length(); i++){
        if(isSeparator(s[i])){
            if(token != "")
                tokens.push_back(token);
            token = "";
        }
        else if(isOparator(s[i])){
            if(token != ""){
                tokens.push_back(token);
                token = "";
            }
            token.push_back(s[i]);
            tokens.push_back(token);
            token = "";
        }
        else{
            token.push_back(s[i]);
        }
    }
    if(token != ""){
        tokens.push_back(token);
    }
    for(int i=0; i<tokens.size(); i++){
        if(isKeyword(tokens[i]))
            cout << '\"' << tokens[i] << "\" is a Keyword" << endl;
        else if(isIdentifier(tokens[i]))
            cout << '\"' << tokens[i] << "\" is an Identifier" << endl;
        else if(isNumber(tokens[i]))
            cout << '\"' << tokens[i] << "\" is a Number" << endl;
        else if(isOparator(tokens[i][0]))
            cout << '\"' << tokens[i] << "\" is an Operator" << endl;
        else
            cout << '\"' << tokens[i] << "\" is an invalid Identifier" << endl;
    }
}

int main(){
    ifstream file;
    string line;
    file.open("program.cpp");
    while(getline(file, line)){
        parse(line);
    }
    file.close();
    return 0;
}


