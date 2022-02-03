#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;

void input() {
    cin >> n;
}

void solve() {
    vector<bool> is_prime(n+1,true);

    for(int i = 2; i <= (int)sqrt(n); i++) {
        for(int j = ((i == 2 || i == 3) ? (i << 1) : i); j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) ans.push_back(i);
    }

    for_each(ans.begin(), ans.end(), [](const int& a) {
        cout << a << ", ";
    });
    cout << endl;
}

int main() {
    input();
    solve();
}