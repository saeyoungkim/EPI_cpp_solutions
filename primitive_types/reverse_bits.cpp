#include <iostream>
#include <bitset>

unsigned long reversed[16] = 
{
    0x0000, 0x1000, 0x0100, 0x1100,
    0x0010, 0x1010, 0x0110, 0x1110,
    0x0001, 0x1001, 0x0101, 0x1101,
    0x0011, 0x1011, 0x0111, 0x1111
};

unsigned long reverse(unsigned long x) {
    const unsigned long mask = 0xF;

    unsigned long ret = 0;
    for(int i = 15; i >= 0; i--) {
        int step = i << 2;
        ret ^= ((x & mask) << step);
        x >>= 4;
    }

    return ret;
}

int main(void) {
    unsigned long x;
    std::cin >> x;
    std::cout << std::bitset<64>(x) << std::endl;
    std::cout << std::bitset<64>(reverse(x)) << std::endl;
}