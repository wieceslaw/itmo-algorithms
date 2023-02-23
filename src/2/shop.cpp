//
// Created by wieceslaw on 20.02.23.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, sm = 0;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k != 0) {
            sm += a[i];
        }
    }
    std::cout << sm << std::endl;
    return 0;
}
