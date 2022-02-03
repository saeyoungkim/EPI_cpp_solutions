#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {1,5,30,22,156,156,156,3,5,5,1,2,4,7,5,5,4,30,30,22,20,30,11,4,5,6,4,66,6,48,23,156,3};

int m;

void input() {
    cin >> m;
    sort(arr.begin(), arr.end());
}

void solve() {
    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ",";
    });
    cout << endl;

    int count = 1;
    int write_idx = 0;

    for(int i = 0; i < arr.size()-1; i++) {
        if(arr[i] != arr[i+1]) {
            int k = count == m ? min(2,m) : count;
            for(int j = 0; j < k; j++) {
                arr[write_idx++] = arr[i];
            }
            count = 1;
        } else {
            count++;
        }
    }

    int k = count == m ? min(2,m) : count;
    for(int j = 0; j < k; j++) {
        arr[write_idx++] = arr.back();
    }

    cout << write_idx << endl;
    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ",";
    });
    cout << endl;
}

int main() {
    input();
    solve();
}