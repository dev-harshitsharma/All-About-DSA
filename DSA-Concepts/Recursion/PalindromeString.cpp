#include <bits/stdc++.h>
using namespace std;

bool RecursivePalindrome(int i, string& myString){
    if(i > myString.size()/2) return true;
    
    if(myString[i]  != myString[myString.size()-1-i]){
        return false;
    }
    return RecursivePalindrome(i+1,myString);
}

int main() {
    string myString ="maadam";
    cout <<"Is the string palindrome?"<<" "<<RecursivePalindrome(0,myString)
}
