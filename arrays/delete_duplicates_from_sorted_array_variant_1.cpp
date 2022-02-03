#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {1,5,30,22,3,5,5,1,2,4,7,5,5,4,30,30,22,20,30,11,4,5,6,4,66,6,48,23,156,3};

int T;

void input() {
    cin >> T;
}

void solve() {
    cout << arr.size() << endl;

    int no_T_idx = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != T) {
            arr[no_T_idx++] = arr[i];
        }
    }

    cout << no_T_idx << endl;
}

int main() {
    input();
    solve();
}