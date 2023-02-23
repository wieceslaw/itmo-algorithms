//
// Created by wieceslaw on 17.02.23.
//

#include <iostream>
#include <vector>

bool passes(std::vector<int> &a, int step, int c) {
    std::size_t ptr = 0;
    c--;
    for (std::size_t i = 0; i < a.size() && c; i++) {
        int range = a[i] - a[ptr];
        if (range >= step) {
            ptr = i;
            c--;
        }
    }
    return c == 0;
}

int bin_search(std::vector<int> &a, int c, int min_step, int max_step) {
    int l = min_step;
    int r = max_step;
    while (std::abs(l - r) > 1) {
        int m = (l + r) / 2;
        if (passes(a, m, c)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n, k;
    int min_r, max_r;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (std::size_t i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i == 1) {
            min_r = a[i] - a[i - 1];
        } else if (i > 1) {
            int r = a[i] - a[i - 1];
            if (r < min_r) {
                min_r = r;
            }
        }
    }
    max_r = (a.back() - a.front()) / (k - 1);
    std::cout << bin_search(a, k, min_r, max_r + 1) << std::endl;
    return 0;
}
