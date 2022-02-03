#include <iostream>
#include <vector>

using namespace std;

int k;

vector<int> arr = {0,1,2,3,4,5,6};

void input() {
    cin >> k;
}

void _solve(int _k) {
    if(_k == 1) {
        return ;
    }

    int kth = 1;
    int idx = 0;
    
    while(kth * (idx+1) < _k) {
        kth *= ++idx;
    }

    if(idx == 0) {
        return ;
    }

    idx = arr.size()-1-idx;
    int j = idx+1;
    while(_k > kth) {
        swap(arr[idx], arr[j++]);
        _k -= kth;
    }

    _solve(_k);
}

void solve() {
    _solve(k);
}

int main() {
    input();
    solve();
    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ",";
    });
    cout << endl;
}