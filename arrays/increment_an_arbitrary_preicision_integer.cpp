#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {9,9,9};

void solve() {
    for_each(arr.begin(), arr.end(), [](const int a) {
        cout << a;
    });
    cout << endl;

    vector<int> ans;
    int carry = 1;
    for(int i = arr.size()-1; i >= 0; i--) {
        int sum = arr[i] + carry;
        int remain = sum % 10;
        ans.push_back(remain);

        carry = sum / 10;
    }

    if(carry) {
        ans.push_back(carry);
    }

    reverse(ans.begin(), ans.end());

    for_each(ans.begin(), ans.end(), [](const int a) {
        cout << a;
    });
    cout << endl;    
}

int main() {
    solve();
}