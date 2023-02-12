//
// Created by wieceslaw on 08.02.23.
//

#include <iostream>

int main() {
    int b, c, d;
    long a;
    long k;
    std::cin >> a >> b >> c >> d >> k;
    if (a * b - c == a) {
        std::cout << a;
        return 0;
    } else if (a * b - c < a) {
        while (k) {
            a *= b;
            a -= c;
            if (a <= 0) {
                break;
            }
            k--;
        }
        if (k) {
            std::cout << 0;
        } else {
            std::cout << a;
        }
    } else {
        while (k) {
            a *= b;
            a -= c;
            if (a > d) {
                a = d;
                break;
            }
            k--;
//            std::cout << a << '\n';
        }
        std::cout << a;
    }
}
