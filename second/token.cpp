#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
bool isSeparator(char ch){
    string value = ",;(){}[]";
    for(int i=0;i<=value.length();i++){
    if(ch==value[i]){
        return true;
    }
    return false;

    }
}
bool isOparator(char ch){
    string value = "+-*/<>=!";
    for(int i=0;i<=value.length();i++){
    if(ch==value[i]){
        return true;
    }
    return false;

    }
}
void parse(string s){
    vector<string> tokens;
    string token = " ";
    for(int i=0;i<s.length();i++){
        
    }

}
int main(){
ifstream file;
string line;
file.open("program.cpp");
while(file){
    getline(file,line);

}
file.close();
return 0;

}
