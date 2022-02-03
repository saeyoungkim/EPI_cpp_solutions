#include <iostream>
#include <vector>

int zeroOrOne() {
    return rand() & 1;
}

int main(void) {
    srand(time(NULL));
    int a, b;
    std::cin >> a >> b;

    int len = b - a + 1;

    std::vector<int> count(len);

    for(int i = 0; i < 1e6; i++) {
        int result = 0;
        do {
            result = 0;
            for(int i = 0; (1 << i) <= len; i++) {
                result = (result << 1) | zeroOrOne();
            }
        } while(result >= len);

        count[result]++;
    }

    for(int i = 0; i < len; i++) {
        std::cout << i+a << " : " << count[i] << std::endl;
    }

    return 0;
}