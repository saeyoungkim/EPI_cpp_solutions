#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {0,0,1,2,2,2,1,1,0,0,1,2,0,0,1,1,2,1,1,1,0,0,0,2,1,0,0};

void solve() {
    int pos_0 = 0, pos_2 = arr.size();
    int curr = 0;
    while(curr < pos_2) {
        if(arr[curr] == 0) {
            swap(arr[curr++], arr[pos_0++]);
        } else if(arr[curr] == 2) {
            swap(arr[curr], arr[--pos_2]);
        } else {
            curr++;
        }
    } 

    for_each(arr.begin(), arr.end(), [](const int a) {
        cout << a << ", ";
    });
    cout << endl;
}

int main() {
    solve();
}