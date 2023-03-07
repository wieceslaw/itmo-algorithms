//
// Created by wieceslaw on 05.03.23.
//

#include <iostream>
#include <stack>

int main() {
    int last = 0;
    std::stack<int> current;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        for (int j = last + 1; j <= tmp; j++) {
            current.push(j);
        }
        if (tmp > last) {
            last = tmp;
        }
        if (current.top() == tmp) {
            current.pop();
        } else {
            std::cout << "Cheater" << std::endl;
            return 0;
        }
    }
    std::cout << "Not a proof" << std::endl;
    return 0;
}
