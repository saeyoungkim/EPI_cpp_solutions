#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<string> arr = {"+", "*", "-", "3", "1", "5", "+", "44", "66"};
    stack<string> stk;
    for(auto v : arr) {
        if(v == "*" || v == "+" || v == "-" || v == "/"){
            stk.push(v);
        } else if(stk.top() == "*" || stk.top() == "+" || stk.top() == "-" || stk.top() == "/") {
            stk.push(v);
        } else {
            int b = stoi(v);
            int a = stoi(stk.top());
            stk.pop();
            
            if(stk.top() == "*") {
                stk.pop();
                stk.push(to_string(a*b));
            } else if(stk.top() == "+") {
                stk.pop();
                stk.push(to_string(a+b));
            } else if(stk.top() == "-") {
                stk.pop();
                stk.push(to_string(a-b));
            } else if(stk.top() == "/") {
                stk.pop();
                stk.push(to_string(a/b));
            }
        }
    }

    while(stk.size() > 1) {
        int a = stoi(stk.top());
        stk.pop();
        int b = stoi(stk.top());
        stk.pop();
        
        if(stk.top() == "*") {
            stk.pop();
            stk.push(to_string(a*b));
        } else if(stk.top() == "+") {
            stk.pop();
            stk.push(to_string(a+b));
        } else if(stk.top() == "-") {
            stk.pop();
            stk.push(to_string(a-b));
        } else if(stk.top() == "/") {
            stk.pop();
            stk.push(to_string(a/b));
        }
    }

    cout << stk.top() << endl;
}