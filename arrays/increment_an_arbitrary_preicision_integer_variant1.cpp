#include <iostream>

using namespace std;

string s, t;

void input() {
    cin >> s;
    cin >> t;
}

void solve() {
    int carry = 0;
    
    string ans = "";

    cout << s << endl;
    cout << t << endl;

    int i = s.size()-1;
    int j = t.size()-1;
    while(i >= 0 || j >= 0 || carry > 0) {
        int sum = carry + (i >= 0 ? s[i]-'0' : 0) + (j >= 0 ? t[j]-'0' : 0);
        ans += (char)('0' + (sum % 10));
        carry = sum / 10;
        if(i>=0) i--;
        if(j>=0) j--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

int main(void) {
    input();
    solve();
}