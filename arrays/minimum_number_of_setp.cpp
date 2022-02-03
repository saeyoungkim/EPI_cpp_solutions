#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {3,2,0,0,2,0,1};
void solve() {
    int step = 0;
    int m = 0;
    int step_in_max = 0;
    int curr = 0;
    for(; curr <= m; curr++) {
        if(curr == arr.size()-1) {
            break;
        }

        step_in_max = max(step_in_max, curr + arr[curr]);

        if(curr == m) {
            step++;
            m = max(m, step_in_max);
        }
    }

    cout << (curr == arr.size()-1 ? step : -1) << endl;
    return ;
}

int main() {
    solve();
}