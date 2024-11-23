// Given a string s containing just the characters '(', ')', '{',  '}', '[' and ']', Write a program to determine if the input string is valid.

#include<iostream>
#include <unordered_map>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> stk;
    unordered_map<char, char> pair = {
        {')','('},
        {'}','{'},
        {']','['}
    };
    for (char c:s){
        if(pair.count(c)){
            //opening bracket
            if(!stk.empty()&& stk.top() == pair[c]){
                stk.pop();
            }else{
                return false;
            }

        }else{
            //closing bracket
            stk.push(c);
        }
    }
    return stk.empty();
}

int main(int argc, char const *argv[])
{
    string input;
    cout << "Enter a string containing brackets: ";
    cin >> input;
    if (isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    return 0;
}
