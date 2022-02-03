#include <iostream>

unsigned long a, b;

void Input() {
    std::cin >> a >> b;
}

unsigned long Plus(unsigned long a, unsigned long b) {
    unsigned long ret = 0;
    unsigned long carry = 0;
    unsigned tmp = 0;
    int i = 0;
    while(a && b) {
        unsigned long left = a&1;
        unsigned long right = b&1;
        tmp = left ^ right ^ carry;
        carry = (left&right&(!carry)) | ((!left)&right&carry) | (left&(!right)&carry) | (left&right&carry);

        ret |= (tmp << i++);
        a >>= 1;
        b >>= 1;
    }

    while(a) {
        tmp = (a&1) ^ carry;
        carry = (a&1) & carry;

        ret |= (tmp << i++);
        a >>= 1;
    }

    while(b) {
        tmp = (b&1) ^ carry;
        carry = (b&1) & carry;

        ret |= (tmp << i++);
        b >>= 1;
    }

    if(carry) {
        ret |= (carry << i);
    }

    return ret;
}

void Solve() {
    unsigned long ans = 0;
    int j = 0;
    while(b) {
        if(b&1) {
            ans = Plus(ans, a << j);
        }

        b >>= 1;
        j++;
    }

    std::cout << ans << std::endl;
    return ;
}

void solve() {
    Input();
    Solve();
}

int main(void) {
    solve();
}