#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > a, b;

void input() {
    int x,y;

    for(int i = 0; i < 4; i++) {
        cin >> x >> y;
        a.push_back({x,y});
    }

    for(int i = 0; i < 4; i++) {
        cin >> x >> y;
        b.push_back({x,y});
    }
}

void solve() {
    vector<int> a_row;
    vector<int> a_col;
    vector<int> b_row;
    vector<int> b_col;

    for(auto coord : a) {
        if(a_row.size() == 0) {
            a_row.push_back(coord[0]);
        } else if(a_row.size() == 1) {
            if(a_row.back() > coord[0]) {
                int tmp = a_row.back();
                a_row.pop_back();
                a_row.push_back(coord[0]);
                a_row.push_back(tmp);
            } else if(a_row.back() < coord[0]){
                a_row.push_back(coord[0]);
            }
        }

        if(a_col.size() == 0) {
            a_col.push_back(coord[1]);
        } else if(a_col.size() == 1) {
            if(a_col.back() > coord[1]) {
                int tmp = a_col.back();
                a_col.pop_back();
                a_col.push_back(coord[1]);
                a_col.push_back(tmp);
            } else if(a_col.back() < coord[1]){
                a_col.push_back(coord[1]);
            }
        }
    }

    for(auto coord : b) {
        if(b_row.size() == 0) {
            b_row.push_back(coord[0]);
        } else if(b_row.size() == 1) {
            if(b_row.back() > coord[0]) {
                int tmp = b_row.back();
                b_row.pop_back();
                b_row.push_back(coord[0]);
                b_row.push_back(tmp);
            } else if(b_row.back() < coord[0]){
                b_row.push_back(coord[0]);
            }
        }

        if(b_col.size() == 0) {
            b_col.push_back(coord[1]);
        } else if(b_col.size() == 1) {
            if(b_col.back() > coord[1]) {
                int tmp = b_col.back();
                b_col.pop_back();
                b_col.push_back(coord[1]);
                b_col.push_back(tmp);
            } else if(b_col.back() < coord[1]){
                b_col.push_back(coord[1]);
            }
        }
    }

    vector<int> rows, cols;
    for(int i = 0; i < 2; i++) {
        rows.push_back(a_row[i]);
        rows.push_back(b_row[i]);
        cols.push_back(a_col[i]);
        cols.push_back(b_col[i]);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    if(a_row[1] == rows[1] || b_row[1] == rows[1]) {
        std::cout << "NULL" << std::endl;
        return ;
    }
    if(a_col[1] == cols[1] || b_col[1] == cols[1]) {
        std::cout << "NULL" << std::endl;
        return ;
    }

    for(int i = 1; i < 3; i++) {
        for(int j = 1; j <3; j++) {
            std::cout << rows[i] << " " << cols[j] << std::endl;
        }
    }
}

int main(void) {
    input();
    solve();
}