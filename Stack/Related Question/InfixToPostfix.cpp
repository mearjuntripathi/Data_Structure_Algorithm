// Question
// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

//     Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
//     Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
//     Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 


#include <bits/stdc++.h>

using namespace std;

int precedance(char op){
    if (op == '^')
        return 3;
    else if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string& infix){
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++){
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z'){
            postfix += infix[i];
        }
        else if (infix[i] == '('){
            s.push(infix[i]);
        }
        else if (infix[i] == ')'){
            while (!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while (!s.empty() && precedance(infix[i]) <= precedance(s.top())){
                if (precedance(infix[i]) == precedance(s.top()) && isRightAssociative(infix[i])){
                    break;
                }
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main(){
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(infix) << endl;
    return 0;
}