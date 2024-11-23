// Write a program to evaluate the Postfix expression.
#include <iostream>
#include <stack>
#include<cctype>
using namespace std;

int performOperation(int operand1, int operand2, char op){
    switch (op)
    {
    case '+': return operand1 + operand2;
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;
    case '-': return operand1 - operand2;
    case '%': return operand1 % operand2;
    default: return 0;
    }
}

bool isOperator(char op){
    return op =='+'||op=='-'||op=='/' || op == '%'|| op=='*';
}

int evaluatePostfix(string postfix){
    stack<int> s;
    for(char c:postfix){
        if(isdigit(c)){
            s.push(c-'0');
        }
        else if(isOperator(c)){
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result = performOperation(op1, op2, c);
            s.push(result);
        }
    }
    return s.top();
}

int main(int argc, char const *argv[])
{
    string postfix;
    cout<<"Enter the postfix expression:- ";
    cin>>postfix;
    int result = evaluatePostfix(postfix);
    cout<<"The Evaluate value is : "<< result<<endl;
    return 0;
}
