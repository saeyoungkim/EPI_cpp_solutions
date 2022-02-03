#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> buildings = {1,6,7,22,15,2,20,60};

int main() {
    stack<int> stk;
    for(int i = buildings.size()-1; i >= 0; i--) {
        if(stk.empty() || stk.top() > buildings[i]) {
            stk.push(buildings[i]);
        } else {
            while(!stk.empty() && stk.top() <= buildings[i]) {
                stk.pop();
            }
            stk.push(buildings[i]);
        }
    }

    cout << stk.size() << endl;
}