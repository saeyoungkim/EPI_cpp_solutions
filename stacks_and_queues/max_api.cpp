#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> _stk;
    vector<int> _max_stk;
public:
    Stack() {};

    void push(int v) {
        _stk.push_back(v);
        _max_stk.push_back((_max_stk.size() > 0 && _max_stk.back() > v) ? _max_stk.back() : v);
    }

    void pop() {
        if(!_stk.size()) {
            return ;
        }

        _stk.pop_back();
        _max_stk.pop_back();
    }

    int top() {
        if(!_stk.size()) {
            exit(1);
        }

        return _stk.back();        
    }

    int max() {
        if(!_max_stk.size()) {
            exit(1);
        }

        return _max_stk.back();        
    }
};

int main() {
    Stack stk = Stack();

    stk.push(1);
    stk.push(5);
    stk.push(2);

    cout << stk.top() << " " << stk.max() << endl;
    stk.pop();
    cout << stk.top() << " " << stk.max() << endl;
    stk.pop();
    cout << stk.top() << " " << stk.max() << endl;
    stk.pop();
}