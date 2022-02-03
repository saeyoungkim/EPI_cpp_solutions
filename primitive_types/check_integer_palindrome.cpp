#include <iostream>

int reverse(int n) {
    int ret = 0;
    while(n) {
        ret = 10*ret + (n%10);
        n /= 10;
    }

    return ret;
}

bool is_palindrome(int n) {
    if(n < 0) {
        return false;
    } 

    return n == reverse(n);
}

int main(void) {
    std::cout << std::boolalpha << is_palindrome(2147447412) << std::endl;
    std::cout << std::boolalpha << is_palindrome(77) << std::endl;
    std::cout << std::boolalpha << is_palindrome(333) << std::endl;
    std::cout << std::boolalpha << is_palindrome(0) << std::endl;
    std::cout << std::boolalpha << is_palindrome(-1) << std::endl;
    std::cout << std::boolalpha << is_palindrome(12) << std::endl;
    std::cout << std::boolalpha << is_palindrome(100) << std::endl;
}