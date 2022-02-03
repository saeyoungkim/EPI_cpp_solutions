#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<string> arr = {"2", "3", "*", "4", "6", "+", "*"};
    stack<string> stk;
    for(auto v : arr) {
        if(v == "*") {
            int a = stoi(stk.top());
            stk.pop();
            int b = stoi(stk.top());
            stk.pop();

            stk.push(to_string(a*b));
        } else if(v == "+") {
            int a = stoi(stk.top());
            stk.pop();
            int b = stoi(stk.top());
            stk.pop();

            stk.push(to_string(a+b));
        } else if(v == "-") {
            int a = stoi(stk.top());
            stk.pop();
            int b = stoi(stk.top());
            stk.pop();

            stk.push(to_string(a-b));
        } else if(v == "/") {
            int a = stoi(stk.top());
            stk.pop();
            int b = stoi(stk.top());
            stk.pop();

            stk.push(to_string(a/b));
        } else {
            stk.push(v);
        }
    }

    cout << stk.top() << endl;
}