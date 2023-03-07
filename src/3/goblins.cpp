//
// Created by wieceslaw on 02.03.23.
//

#include <iostream>
#include <deque>
#include <cstddef>

class GoblinQueue {
    std::size_t size = 0;
    std::deque<int> front_deq;
    std::deque<int> back_deq;

public:
    void put_default(int n) {
        back_deq.push_back(n);
        if (size % 2 == 0) {
            front_deq.push_back(back_deq.front());
            back_deq.pop_front();
        }
        size++;
    }

    void put_privileged(int n) {
        if (size % 2 == 0) {
            front_deq.push_back(n);
        } else {
            back_deq.push_front(n);
        }
        size++;
    }

    int pop() {
        int value = front_deq.front();
        front_deq.pop_front();
        if (size % 2 == 0 && !back_deq.empty()) {
            front_deq.push_back(back_deq.front());
            back_deq.pop_front();
        }
        size--;
        return value;
    }
};

int main() {
    GoblinQueue queue;
    int n;
    std::cin >> n;
    for (std::size_t i = 0; i < n; i++) {
        char command;
        int k;
        std::cin >> command;
        if (command == '+') {
            std::cin >> k;
            queue.put_default(k);
        } else if (command == '*') {
            std::cin >> k;
            queue.put_privileged(k);
        } else {
            std::cout << queue.pop() << '\n';
        }
    }
    return 0;
}
