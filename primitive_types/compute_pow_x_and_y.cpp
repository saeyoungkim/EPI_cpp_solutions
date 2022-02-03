#include <iostream>

double x;
int y;

void Input() {
    std::cin >> x >> y;
}

void Solve() {
    double ret = 1.0;
    if(y < 0) {
        y *= -1;
        x = 1.0 / x;
    }

    while(y) {
        if(y&1) {
            ret *= x;
        }

        x *= x; y >>= 1;
    }

    std::cout << ret << std::endl;
    return ;
}

void solve(){
    Input();
    Solve();
}

int main(void) {
    solve();
}