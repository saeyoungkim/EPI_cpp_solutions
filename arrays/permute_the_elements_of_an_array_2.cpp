#include <iostream>
#include <vector>

using namespace std;

vector<char> arr = {'a', 'b', 'c', 'd'};
vector<int> permutation = {1,2,0,3};

int main() {
    for(int i = 0; i < permutation.size(); i++) {
        int next = i;
        while(permutation[next]) {
            swap(arr[i], arr[permutation[next]]);

            permutation[next] = -1;
            next = permutation[next];
        }
    }

    for_each(arr.begin(), arr.end(), [](const char c) {
        cout << c << ",";
    });
    cout << endl;
}