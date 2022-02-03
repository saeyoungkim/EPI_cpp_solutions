#include <iostream>

#include <iostream>
#include <vector>

using namespace std;

vector<int> permutation = {2,0,4,5,1,6,3,7};

// 2 0 4 1
// 0 -> 2
// 2 -> 4
// 4 -> 1
// 1 -> 0

// 0 <- 2
// 2 <- 4
// 4 <- 1
// 1 <- 0
// 1 4 0 2

// 5 6 3
// 3 -> 5
// 5 -> 6
// 6 -> 3

// 3 <- 5
// 5 <- 6
// 6 <- 3
// 6 3 5

int main(void) {
    for(int i = 0; i < permutation.size(); i++) {
        int j = permutation[i];
        int prev = i;
        int tmp;

        if(j < 0) {
            continue;
        }

        while(permutation[j] >= 0) {
            tmp = permutation[j];
            permutation[j] = -prev;
            prev = j;
            j = tmp;
        }
    }

    for(int i = 0; i < permutation.size(); i++) {
        permutation[i] = -permutation[i];
    }

    for_each(permutation.begin(), permutation.end(), [](const int& a) {
        cout << a << ",";
    });
    cout << endl;
}