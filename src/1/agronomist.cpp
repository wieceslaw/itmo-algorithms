//
// Created by wieceslaw on 08.02.23.
//
#include <iostream>

int main() {
    int n, tmp;
    std::cin >> n;
    std::cin >> tmp;
    int ptr = 0, last = tmp, last_i = 0, count = 1, len;
    int mx_len = 0, mx_s = 0, mx_e = 0;
    for (int i = 1; i < n; i++) {
        std::cin >> tmp;
        if (tmp == last) {
            count++;
            if (count >= 3) {
                len = i - ptr;
                if (len > mx_len) {
                    mx_len = len;
                    mx_s = ptr;
                    mx_e = i - 1;
                }
                last_i++;
                ptr = last_i;
                count--;
            }
        } else {
            last = tmp;
            count = 1;
            last_i = i;
        }
    }
    len = n - ptr;
    if (len > mx_len) {
        mx_s = ptr;
        mx_e = n - 1;
    }
    std::cout << mx_s + 1 << ' ' << mx_e + 1 << std::endl;
}
