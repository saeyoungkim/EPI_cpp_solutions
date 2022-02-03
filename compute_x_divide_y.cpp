#include <iostream>

unsigned divide(unsigned a, unsigned b) {
    unsigned ret = 0;
    const int power = 32;
    unsigned long long b_power = static_cast<unsigned long long>(b) << power;

    while(a >= b) {
        while(b_power > a) {
            b_power >>= 1;
            --power;
        }

        ret += (1U << power);
        ret -= b_power;
    }

    return ret;
}