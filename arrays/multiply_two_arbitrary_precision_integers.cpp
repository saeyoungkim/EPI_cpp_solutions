#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> A, B;

vector<vector<int>> K;

void input() {
    string A1, B1;
    cin >> A1;
    for(int i = A1.front() == '-' ? 1 : 0; i < A1.size(); i++) {
        A.push_back(A1[i] - '0');
    }

    if(A1.front() == '-') {
        A.front() *= -1;
    }

    cin >> B1;
    for(int i = B1.front() == '-' ? 1 : 0; i < B1.size(); i++) {
        B.push_back(B1[i] - '0');
    }

    if(B1.front() == '-') {
        B.front() *= -1;
    }

    K.resize(A1.size()+B1.size());  

    cout << "INPUT DONE" << endl;  
}

void solve() {
    bool is_minus = (A.front() > 0 && B.front() < 0) || (A.front() < 0 && B.front() > 0);
    
    if(A.front() < 0) {
        A.front() *= -1;
    }

    if(B.front() < 0) {
        B.front() *= -1;
    }

    int s = 0;
    for(int i = A.size()-1; i >= 0; i--) {
        int idx = s;
        int carry = 0;
        int sum = 0;
        int j = B.size()-1;
        while(j >= 0 || carry) {
            sum = j < 0 ? carry  : carry + A[i] * B[j];
            K[idx++].push_back(sum % 10);
            carry = sum / 10;
            j--;
        }
        s++;
    }
    
    vector<int> ans;

    int carry = 0;
    int i = 0;
    while(carry || !K[i].empty()) {
        int sum = carry;
        for(auto n : K[i]) {
            sum += n;
        }

        ans.push_back(sum % 10);
        carry = sum / 10;
        i++;
    }

    reverse(ans.begin(), ans.end());

    if(is_minus) {
        ans.front() *= -1;
    }

    for_each(ans.begin(), ans.end(), [](const auto& a) {
        cout << a;
    });
}

int main() {
    input();
    solve();
}