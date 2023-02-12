//
// Created by wieceslaw on 11.02.23.
//

#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;
        if (n % k == 0) {
            int s;
            s = n / k;
            std::cout << k * (k - 1) / 2 * s * s << '\n';
        } else {
            int s_a, s_b, k_a, k_b;
            k_a = n % k;
            k_b = k - k_a;
            s_b = n / k;
            s_a = s_b + 1;
            std::cout << (s_a * s_a * k_a * (k_a - 1) / 2) + (s_a * s_b * k_a * k_b) + (s_b * s_b * k_b * (k_b - 1) / 2) << '\n';
            // a-a: s_a * s_a * k_a * (k_a - 1) / 2
            // a-b: s_a * s_b * k_a * k_b
            // b-b: s_b * s_b * k_b * (k_b - 1) / 2
        }
    }
}
