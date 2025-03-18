#include<iostream>
#include<string>
using namespace std;
int main(){

    cout<<"enter string :";
    string s;
    getline(cin,s);
    bool valid = false;
    
    if(s[0]=='/'&& s[1]=='/'){
        valid = true;
    }
    if((s[0]=='/')&&(s[1]=='*')&&(s[s.length()-2]=='*')&&(s[s.length()-1]=='/')){
        valid = true;
    }
    if(valid){
        cout<<"comment"<<endl;

    }
    else{
        cout<<"not comment"<<endl;
    }
    return 0;
}