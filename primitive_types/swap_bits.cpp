#include <iostream>
#include <bitset>

void swap_bits(unsigned long &x, int i, int j) {
    unsigned long a = x & (1 << i);
    unsigned long b = x & (1 << j);

    if((a && b) || (!a && !b)) {
        return ;
    }

    x ^= (1 << i);
    x ^= (1 << j);

    return ;
}

void swap_bits_2(unsigned long &x, int i, int j) {
    if(((x >> i) & 1) != ((x >> j) & 1)) {
        unsigned long mask = (1 << i) | (1 << j);
        x ^= mask;
    }
}

int main(void) {
    unsigned long x = 1512312;

    std::cout << std::bitset<32>(x) << std::endl;
    swap_bits(x, 0, 4);
    std::cout << std::bitset<32>(x) << std::endl;

    x = 1512312;
    std::cout << std::bitset<32>(x) << std::endl;
    swap_bits_2(x, 0, 4);
    std::cout << std::bitset<32>(x) << std::endl;
}
