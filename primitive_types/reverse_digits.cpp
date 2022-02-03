#include <iostream>

int reverse(int n) {
    int ret = 0;
    while(n) {
        ret = 10*ret + (n%10);
        n /= 10;
    }

    return ret;
}

std::string reverse(std::string str) {
    std::reverse(str.front() == '-' ? str.begin()+1 : str.begin() , str.end());
    
    return str;
}

int main(void) {
    int N;
    std::cin >> N;
    std::cout << N << std::endl;
    std::cout << reverse(N) << std::endl;    

    int str;
    std::cin >> str;
    std::cout << str << std::endl;
    std::cout << reverse(str) << std::endl;  
}