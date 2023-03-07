//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<char>> map_t;

inline char calc(char c) {
    if (c == '.') {
        return 1;
    } else if (c == 'W') {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int n, m;
    int x1, y1;
    int x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    map_t map(n);
    for (int i = 0; i < n; i++) {
        map[i] = std::vector<char>(m);
        for (int j = 0; j < m; j++) {
            char tmp;
            std::cin >> tmp;
            map[i][j] = calc(tmp);
        }
    }

    return 0;
}
