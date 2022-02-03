#include <iostream>
#include <vector>

using namespace std;

vector<char> arr = {'a', 'b', 'c', 'd'};
vector<int> permutation = {2,1,0,3};

int main() {
    for(int i = 0; i < permutation.size(); i++) {
        if(permutation[i]) {
            char curr_c = arr[i];
            char next_c;
            int curr_i = i;
            int next_i;
            while(permutation[curr_i] >= 0) {
                next_i = permutation[curr_i];
                permutation[curr_i] *= -1;

                next_c = arr[next_i];
                arr[next_i] = curr_c;
                
                curr_c = next_c;
                curr_i = next_i;
            }
        }
    }

    for_each(arr.begin(), arr.end(), [](const auto& c) {
        cout << c << ", ";
    });
    cout << endl;
}