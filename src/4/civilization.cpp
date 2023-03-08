//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>
#include <cstddef>
#include <queue>

typedef struct {
    std::uint16_t x;
    std::uint16_t y;
    std::uint64_t r;
    bool visited;
} point_t;
typedef std::vector<std::vector<std::uint8_t>> map_t;
typedef std::vector<std::vector<point_t>> graph_t;

auto compare = [](point_t* p1, point_t* p2) { return p1->r < p2->r; };

inline char calc(std::uint8_t c) {
    if (c == '.') {
        return 1;
    } else if (c == 'W') {
        return 2;
    } else {
        return 0;
    }
}



void dijkstra(std::uint16_t n, std::uint16_t m,
              std::uint16_t x1, std::uint16_t y1,
              std::uint16_t x2, std::uint16_t y2) {
    // fill graph
    graph_t graph = graph_t(n);
    for (uint16_t i = 0; i < n; i++) {
        graph[i] = std::vector<point_t>(m);
        for (uint16_t j = 0; j < m; j++) {
            graph[i][j] = {i, j, INT64_MAX, false};
        }
    }

    //
    std::priority_queue<point_t*, std::vector<point_t*>, decltype(compare)> queue(compare);
    queue.push(&graph[x1][y1]);

    /*
     * while () {
     *     ...
     *     for p : unvisited_near(current) {
     *     new_r = current.r + map[p]
     *     p.r = min(p.r, new_r)
     *     }
     *     if (p == dest) {
     *          return p
     *     }
     *     p.visited = true
     *     current = queue.top()
     *     ...
     * }
     */
}

int main() {
    std::uint16_t n, m, x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    map_t map(n);
    for (int i = 0; i < n; i++) {
        map[i] = std::vector<uint8_t>(m);
        for (int j = 0; j < m; j++) {
            char tmp;
            std::cin >> tmp;
            map[i][j] = calc(tmp);
        }
    }
    dijkstra(n, m, x1, y1, x2, y2);
    return 0;
}
