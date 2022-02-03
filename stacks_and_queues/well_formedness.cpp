#include <iostream>
#include <stack>

using namespace std;

string brackets = "[()[]{()()}]";

int main() {
    stack<char> stk;

    for(auto c : brackets) {
        if(c == '[' || c == '{' || c == '(') {
            stk.push(c);
        } else if(c == ')') {
            if(!stk.empty() && stk.top() == '(') {
                stk.pop();
            }
        } else if(c == ']') {
            if(!stk.empty() && stk.top() == '[') {
                stk.pop();
            }
        } else if(c == '}') {
            if(!stk.empty() && stk.top() == '{') {
                stk.pop();
            }
        }
    }

    cout << boolalpha << (stk.size() == 0) << endl;
}