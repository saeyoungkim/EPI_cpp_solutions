#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {1,5,3,6,22,1};

vector<int> subsets;

int k;

void input() {
    cin >> k;
}

void solve() {
    srand(time(NULL));

    
    while(subsets.size() != k) {
        subsets.clear();
        for(auto a : arr) {
            if(rand() & 1) {
                subsets.push_back(a);
            }
        }
    }
}

int main() {
    input();
    solve();

    for_each(subsets.begin(), subsets.end(), [](const int a) {
        cout << a << " ";
    });
    cout << endl;
}