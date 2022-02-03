#include <iostream>
#include <vector>

using namespace std;

vector<int> stock = {310,315,275,295,260,270,290,230,255,250};

void solve() {
    int min_stock = INT_MAX;
    int max_profit = 0;
    // if we sell the stock at index of i, the max profit is stock[i] - min(stock[0], ... , stock[i-1]) 
    for(int i = 0; i < stock.size(); i++) {
        min_stock = min(min_stock, stock[i]);
        max_profit = max(max_profit, stock[i] - min_stock);
    }

    cout << max_profit << endl;
    return ;
}

int main() {
    solve();
}