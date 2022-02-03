#include <iostream>
#include <vector>

using namespace std;

vector<char> arr = {'a', 'b', 'c', 'd'};
vector<bool> is_visited(arr.size(), false);

void _recursive(const vector<char>& arr, vector<vector<char>>& ans, vector<char>& tmp) {
    if(tmp.size() == arr.size()) {
        ans.push_back(tmp);
        return ;
    }

    for(int i = 0; i < arr.size(); i++) {
        if(!is_visited[i]) {
            is_visited[i] = true;
            tmp.push_back(arr[i]);
            _recursive(arr, ans, tmp);
            tmp.pop_back();
            is_visited[i] = false;
        }
    }

    return ;
}

void solve() {
    vector<vector<char>> ans;
    vector<char> tmp;
    _recursive(arr, ans, tmp);

    for_each(ans.begin(), ans.end(), [](const vector<char>& v) {
        for_each(v.begin(), v.end(), [](const char& c) {
            cout << c << ",";
        });
        cout << endl;
    });
    cout << endl;
}

int main() {
    solve();
}
