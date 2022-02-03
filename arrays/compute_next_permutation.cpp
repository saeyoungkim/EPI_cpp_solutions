// 0 1 2 3
// 0 1 3 2
// 0 2 1 3
// 0 2 3 1
// 0 3 1 2
// 0 3 2 1
// 1 0 2 3
// 1 0 3 2

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {3,2,1,0};

int main() {
    if(arr.size() == 1) {
        cout << arr.front() << endl;
        return 0;
    }

    int i = arr.size()-2;
    for(; i >= 0; i--) {
        if(arr[i] < arr[i+1]) {
            break;
        }
    }

    if(i == -1) {
        cout << "{}" << endl;
        return 0;
    }

    int diff = INT_MAX;
    int cand = i;
    for(int j = i+1; j < arr.size(); j++) {
        if(arr[j] > arr[i] && arr[j] - arr[i] < diff) {
            cand = j;
            diff = arr[j] - arr[i];
        } 
    }

    swap(arr[cand],arr[i]);

    sort(arr.begin()+i+1, arr.end());

    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ",";
    });
    cout << endl;
}