#include<iostream>
#include<string>
using namespace std;

bool isA(string s) {
    if (s.empty() || s[i] != 'b') return false; 
    
    int i = 1;
    while (i < s.length() && s[i] == 'a') {
        i++; 
    }
    
   
    
    return i == s.length(); 





    
}
int main(){
    cout << "Enter your string: ";
    string s;
    cin >> s;
    cout << (isA(s) ? "Accepted" : "Rejected") << endl;

}