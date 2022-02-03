#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {2,3,5,5,7,11,11,11,13};

void solve() {
    int non_duplicated_idx = 0;
    int i = 0;
    while(i < arr.size()) {
        int v = arr[i];

        arr[non_duplicated_idx++] = arr[i++];
            
        while(arr[i] == v) {
            i++;
        }
    }

    for(int j = non_duplicated_idx; j < arr.size(); j++) {
        arr[j] = 0;
    }

    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << " ";
    });
    cout << endl;

    cout << non_duplicated_idx << endl;

    cout << endl;
}

int main() {
    solve();
}