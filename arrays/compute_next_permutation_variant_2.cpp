#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {0,1,2,3,4,5,6};

void solve() {
    int i = arr.size()-2;
    while(i >= 0) {
        if(arr[i] > arr[i+1]) {
            break;
        }

        i--;
    }

    if(i == -1) {
        arr = {};
        return ;
    }

    for(int k = arr.size()-1; k > i; k--) {
        if(arr[k] < arr[i]) {
            swap(arr[i], arr[k]);
            break;
        }
    }

    reverse(arr.begin()+i+1, arr.end());
    return ;
}

int main() {
    solve();
    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ",";
    });
    cout << endl;
}