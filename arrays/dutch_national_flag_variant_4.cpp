#include <iostream>
#include <vector>

using namespace std;

vector<bool> arr = {true,false,false,false,false,true,true,false,true,true,false,true,true,false,false,false,true};

void solve() {
    int false_pos = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(!arr[i]) {
            swap(arr[false_pos++], arr[i]);
        }
    }

    for_each(arr.begin(), arr.end(), [](const int a) {
        cout << a << ", ";
    });
    cout << endl;
}

int main(void) {
    solve();
}