//
// Created by wieceslaw on 17.02.23.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(std::pair<char, int> &a, std::pair<char, int> &b) {
    return a.second > b.second;
}

struct Cls {
    Cls(char c, double d, int i);
private:
    char c;
    double d;
    int i;
};

struct Clazz {
    char c;
    double d;
    int i;
};


double &get_d(Cls &cls) {
    double *p = (double*) (((char*) &cls) + offsetof(Clazz, d));
    return *p;
}

int &get_i(Cls &cls) {
    int *p = (int*) (((char*) &cls) + offsetof(Clazz, i));
    return *p;
}

int main() {
    std::string line;
    int symbols[26] = {0};
    std::cin >> line;
    for (const char sym : line) {
        symbols[sym - 'a'] += 1;
    }
    int weights[26];
    for (size_t i = 0; i < 26; i++) {
        std::cin >> weights[i];
    }
    std::vector<std::pair<char, int>> pairs;
    for (char i = 0; i < 26; i++) {
        if (symbols[i] >= 2) {
            pairs.emplace_back('a' + i, weights[i]);
            symbols[i] -= 2;
        }
    }
    std::sort(pairs.begin(), pairs.end(), compare);
    for (auto it = pairs.begin(); it != pairs.end(); it++) {
        std::cout << it->first;
    }
    for (char i = 0; i < 26; i++) {
        while (symbols[i]) {
            symbols[i]--;
            std::cout << char(i + 'a');
        }
    }
    for (auto it = pairs.rbegin(); it != pairs.rend(); it++) {
        std::cout << it->first;
    }
    return 0;
}
