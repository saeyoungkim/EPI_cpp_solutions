#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {0,0,1,3,2,2,3,1,3,0,0,1,2,0,0,3,1,2,1,1,1,3,0,0,2,1,0,0,3,3};

void solve() {
    int pos_0 = 0, pos_3 = arr.size();
    int curr = 0;
    while(curr < pos_3) {
        if(arr[curr] == 0) {
            swap(arr[curr++], arr[pos_0++]);
        } else if(arr[curr] == 3) {
            swap(arr[curr], arr[--pos_3]);
        } else {
            curr++;
        }
    } 

    curr = pos_0;
    int pos_1 = pos_0;
    while(curr < pos_3) {
        if(arr[curr] == 1) {
            swap(arr[curr++], arr[pos_1++]);
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