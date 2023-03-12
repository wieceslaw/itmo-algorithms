//
// Created by wieceslaw on 05.03.23.
//

#include <iostream>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    int n, k;
    std::cin >> n >> k;
    ordered_set oset;
    for (int i = 1; i <= n; i++) {
        oset.insert(i);
    }
    int start = k - 1;
    std::cout << start + 1 << ' ';
    for (int size = n; size > 1; size--) {
        oset.erase(oset.find_by_order(start));
        if (start == size - 1) {
            start = (k - 1) % (size - 1);
        } else {
            start = (start + k - 1) % (size - 1);
        }
        std::cout << *oset.find_by_order(start) << ' ';
    }
    return 0;
}

// 3 1 3 1 1
// ---------
// 1 2 3 4 5 - 3
// 1 2 4 5   - 1
// 2 4 5     - 5
// 2 4       - 2
// 4         - 4
// ---------
// 3 1 5 2 4