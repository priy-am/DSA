// Given a string s containing just the characters '(', ')', '{',  '}', '[' and ']', Write a program to determine if the input string is valid.

#include<iostream>
#include <unordered_map>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> stk;
    unordered_map<char, char> pair = {
        {')','()'},
        {'}','{}'},
        {']','['}
    };
    for (char c:s){
        if(pair.count(c)){
            //opening bracket

        }else{
            //closing bracket
            stk.push(c);
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
