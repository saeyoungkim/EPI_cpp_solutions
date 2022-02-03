#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {3,2,0,0,2,0,1};

void solve() {
    int m = 0;
    int curr = 0;
    for(;curr <= min(m, (int)arr.size()-1); curr++) {
        m = max(m, curr + arr[curr]);
    }

    cout << (curr == arr.size() ? "YES" : "NO") << endl;
}

int main() {
    solve();
}