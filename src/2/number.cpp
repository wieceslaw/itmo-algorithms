//
// Created by wieceslaw on 09.02.23.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::string &lhs, const std::string &rhs) {
    return lhs + rhs > rhs + lhs;
}

int main() {
    std::string line;
    std::vector<std::string> parts;
    while (std::cin >> line) {
        parts.push_back(line);
    }
    std::sort(parts.begin(), parts.end(), compare);
    for (const auto& part : parts) {
        std::cout << part;
    }
    std::cout << std::endl;
}
