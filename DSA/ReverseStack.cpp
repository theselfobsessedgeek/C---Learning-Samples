#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    
    //base-case
     
    //base-case
    if(input.empty()) return;
    int temp = input.top();
    input.pop();
    extra.push(temp);
    reverseStack(input,extra);
    input.push(temp);
    extra.pop();
}
int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    while (!extra.empty()) {
        cout << extra.top() << " ";
        extra.pop();
    }
}