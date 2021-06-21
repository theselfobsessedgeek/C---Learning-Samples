#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string exp) 
{
    stack<char> stack;

    for(int i = 0; i<exp.length();i++){
        if(exp[i]=='(') stack.push(exp[i]);
        if(exp[i]=='{') stack.push(exp[i]);
        if(exp[i]=='[') stack.push(exp[i]);
        if(exp[i]=='}'&& !stack.empty()) stack.pop();
        if(exp[i]==')'&& !stack.empty()) stack.pop();
        if(exp[i]==']'&& !stack.empty()) stack.pop();

    }

    return stack.empty();
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}