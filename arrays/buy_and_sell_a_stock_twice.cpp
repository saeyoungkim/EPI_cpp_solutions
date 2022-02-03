#include <iostream>
#include <vector>

using namespace std;

vector<int> stocks = {310,315,275,295,260,270,290,230,255,250};

void solve() {
    int one_sell = INT_MAX;
    int one_buy = INT_MIN;
    int two_sell = INT_MAX;
    int two_buy = INT_MIN;

    for(auto stock : stocks) {
        one_sell = min(stock, one_sell);
        one_buy = max(one_buy, stock - one_sell);
        two_sell = min(two_sell, stock - one_buy);
        two_buy = max(two_buy, stock - two_sell);
    }

    cout << two_buy << endl;
}

int main(void) {
    solve();
}