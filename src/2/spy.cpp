//
// Created by wieceslaw on 23.02.23.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>
#include <map>
#include <queue>

// https://www.cs.princeton.edu/courses/archive/spr03/cs226/assignments/burrows.html
// https://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform

int main() {
    std::size_t k;
    std::string last_column;
    std::cin >> k >> last_column;
    std::vector<std::size_t> next(last_column.size());
    std::string first_column = last_column;
    std::sort(first_column.begin(), first_column.end());
    std::map<char, std::queue<std::size_t>> char_indexes;
    for (std::size_t i = 0; i < last_column.size(); i++) {
        char_indexes[last_column[i]].push(i);
    }
    for (std::size_t i = 0; i < first_column.size(); i++) {
        char c = first_column[i];
        next[i] = char_indexes[c].front();
        char_indexes[c].pop();
    }
    std::size_t ptr = k - 1;
    for (std::size_t i = 0; i < first_column.size(); i++) {
        std::cout << first_column[ptr];
        ptr = next[ptr];
    }
    return 0;
}
