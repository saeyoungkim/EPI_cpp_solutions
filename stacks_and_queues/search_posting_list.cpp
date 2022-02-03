#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* jump;

    Node(int _v) : val(_v), next(nullptr), jump(nullptr) {};
};

int main() {

}