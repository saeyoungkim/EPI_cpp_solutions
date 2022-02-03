#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int tmp;
    vector<int> arr;
    while(N--) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ", ";
    });
    cout << endl;

    int even = 0;
    int odd = arr.size();
    int i = 0;
    while(even < odd) {
        if(arr[i] & 1) {
            swap(arr[i], arr[--odd]);
        } else {
            swap(arr[i++], arr[even++]);
        }
    }

    for_each(arr.begin(), arr.end(), [](const int& a) {
        cout << a << ", ";
    });
    cout << endl;
}