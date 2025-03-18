#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    bool valid = true;
    string keyword[]={
        "auto","break","case","char","const","continue","default","do","double","else",
        "extern","float","for","goto","if","int","long","register","return","short",
        "signed","sizeof","static","switch","typeof","union","unsigned","void","volatile","while"
    };
    cin>>s;
    for(int i=0;i<(sizeof(keyword)/sizeof(string));i++){
        if(s==keyword[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        if((s[0]>='0')&&(s[0]<='9')){
            valid = false;
        }
    }
    if(valid){
        for(int i=0;i<s.length();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')||(s[i]=='_')){
                continue;
            }
            else{
                valid=false;
                break;
            }
        }
    }
    if(valid){
        cout<<"valid identifier \n";
    }
    else{
        cout<<"invalid \n";
    }
}