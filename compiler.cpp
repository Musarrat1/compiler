#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter String :";
    string s;
    cin>>s;
    bool valid =true;
    string key[]= {"int","cout","cin","main","using","namespace",
    "bool"};
    for(int i=0;i<sizeof(key)/sizeof(string);i++){
        if(s==key[i]){
            valid= false;
            break;

        }
    }
        if(valid){
            if(s[0]>='0'&& s[0]<='9'){
                valid = false;
    
            }
        }
    
  
    if(valid){
        for(int i=0;i<s.length();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                continue;
            }
            else{
                valid = false;
                break;
            }
        }
    }
    if(valid){
        cout<<"identifier"<<endl;

    }
    else{
        cout<<"Not identifier"<<endl;
    }
    
}