//
// Created by wieceslaw on 04.03.23.
//

#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::multiset<int> set;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        set.insert(a[i]);
        if (set.size() == k) {
            std::cout << *set.begin() << ' ';
            set.erase(set.find(a[i - k + 1]));
        }
    }
    return 0;
}
