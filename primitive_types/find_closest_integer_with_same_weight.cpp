#include <iostream>
#include <bitset>

using namespace std;
unsigned int x;

// 2^m - 2 ^m-1 < 2^(m+1) - 2^m
// most right bit shift to right;

void Input() {
    cin >> x;
}

void Solve() {
    std::cout << bitset<64>(x) << std::endl;
    std::cout << x << endl;

    if(!x) {
        cout << 0 << endl;
        return ;
    }
    // has 0 after the most right bit of 1
    unsigned long right_bit;
    if(!(x&1)) {
        right_bit = x ^ (x & (x-1));
    } else {
        // find first 0 bit
        unsigned long mask = -1;
        mask ^= x;
        right_bit = mask ^ (mask & (mask-1));
    }
    x ^= right_bit;
    x ^= (right_bit >> 1);

    std::cout << bitset<64>(x) << std::endl;
    std::cout << x << endl;
}

void solve() {
    Input();
    Solve();
}

int main(void){
    solve();
}