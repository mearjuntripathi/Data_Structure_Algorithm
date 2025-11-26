#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string postToPre(string post_exp){
    stack<string> s;
    string op1, op2;
    for (int i = 0; i < post_exp.length(); i++){
        if (isOperator(post_exp[i])){
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            string temp = post_exp[i] + op2 + op1;
            s.push(temp);
        }
        else{
            s.push(string(1, post_exp[i]));
        }
    }
    return s.top();   
}

int main()
{
    string post_exp = "ABC/-AK/L-*";

    // Function call
    cout << "Prefix : " << postToPre(post_exp) << endl;
    return 0;
}