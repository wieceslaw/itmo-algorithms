//
// Created by wieceslaw on 04.03.23.
//

#include <iostream>
#include <queue>
#include <vector>

class Compare {
public:
    bool operator()(std::pair<int, int> lhs, std::pair<int, int> rhs) {
        return lhs.second > rhs.second;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> queue;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        queue.emplace(i, tmp);
        if (i >= k - 1) {
            while (i - queue.top().first >= k) {
                queue.pop();
            }
            std::cout << queue.top().second << ' ';
        }
    }
    return 0;
}
