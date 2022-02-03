#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {1,1,1,2,2,2,2,2,3,3,5,1,2,2,2,5,2,3,4,5,6,7,7,77,7,7,77,7,7,34,2,24,2,1,5,5,2,6,3,4,2};

void solve() {
    int max_sub_length_so_far = 1;
    int curr_sub_length = 1;
    for(int i = 1 ; i < arr.size(); i++) {
        if(arr[i] != arr[i-1]) {
            curr_sub_length = 1;
        } else {
            curr_sub_length++;
        }
        max_sub_length_so_far = max(max_sub_length_so_far, curr_sub_length);
    }

    cout << max_sub_length_so_far << endl;
}

int main() {
    solve();
}