//
// Created by wieceslaw on 08.02.23.
//

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <queue>


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::map<std::string, std::stack<int>> map;
    std::stack<std::queue<std::string>> stack;
    stack.emplace();

    for (std::string line; std::getline(std::cin, line);) {
        if (line == "{") {
            stack.emplace();
        } else if (line == "}") {
            while (!stack.top().empty()) {
                map[stack.top().front()].pop();
                stack.top().pop();
            }
            stack.pop();
        } else {
            size_t i = line.find('=');
            std::string var = line.substr(0, i);
            std::string val = line.substr(i + 1, line.size() - i);

            int new_val;
            if (val.back() >= '0' && val.back() <= '9') {
                new_val = std::stoi(val);
            } else {
                if (!map.count(val)) {
                    new_val = 0;
                } else {
                    if (map[val].empty()) {
                        new_val = 0;
                    } else {
                        new_val = map[val].top();
                    }
                }
                std::cout << new_val << '\n';
            }
            stack.top().push(var);
            map[var].push(new_val);
        }
    }
}