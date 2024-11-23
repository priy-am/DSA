/* The precedence for operators generally follows this order (highest to lowest):
 *, /, % (Multiplication, Division, Modulus)
 +, - (Addition, Subtraction)
 Parentheses ()*/

// Write a program to convert Infix expression into Postfix expression and also analyze its Complexity.

#include <iostream>
#include <stack>
#include <cctype> //for use isalnum
#include <string>
using namespace std;

int precedence(char op){
    if(op == '+'|| op== '-'){
        return 1;
    }
    if(op == '*' ||op == '/' || op == '%'){
        return 2;
    }
    return 0; 
}
bool isOperator(char op){
    return op =='+'||op=='-'||op=='/' || op == '%'|| op=='*'||op=='^'||op=='(';
}

string infixToPostfix(string& infix){
    stack<char> s;
    string postfix = "";
    for(char c:infix){
        if(isalnum(c)){
            postfix += c;
        }
        else if(c=='('){
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') { 
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
        }
        else if(isOperator(c)){
            while(!s.empty() && precedence(s.top()) >= precedence(c)){
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main(int argc, char const *argv[])
{
    string infix;
    cout<<"Enter the infix expression:-";
    cin>>infix;
    string postfix = infixToPostfix(infix);
    cout<<"Postfix expression "<<postfix<<endl;
    return 0;
}
