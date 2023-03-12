//
// Created by wieceslaw on 24.02.23.
//

#include <iostream>
#include <queue>
#include <vector>
#include <deque>

int main() {
    int n, k, p, c = 0, size = 0;
    std::cin >> n >> k >> p;
    std::vector<std::deque<int>> next(n);
    std::vector<int> a(p);
    std::priority_queue<int> queue;
    std::vector<bool> values(n, false);

    for (int i = 0; i < p; i++) {
        int tmp;
        std::cin >> tmp;
        tmp--;
        a[i] = tmp;
        next[tmp].push_back(i);
    }

    for (int i = 0; i < p; i++) {
        int el = a[i];
        if (!values[el]) {
            c++;
            if (size == k) {
                size--;
                values[a[queue.top()]] = false;
                queue.pop();
            }
            size++;
            values[el] = true;
        }
        next[el].pop_front();
        if (!next[el].empty()) {
            queue.push(next[el].front());
        } else {
            size--;
            values[el] = false;
        }
    }

    std::cout << c << std::endl;
    return 0;
}
