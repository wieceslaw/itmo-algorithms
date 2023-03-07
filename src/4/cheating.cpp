//
// Created by wieceslaw on 06.03.23.
//

// https://en.wikipedia.org/wiki/Bipartite_graph
// https://en.wikipedia.org/wiki/Graph_coloring

#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_set>

typedef enum {
    NOCOL = 0,
    COL1 = 1,
    COL2 = 2
} color_t;
typedef std::vector<std::unordered_set<std::int8_t>> graph_t;
typedef std::vector<color_t> colors_t;


inline color_t i_color(color_t color) {
    if (color == COL1)
        return COL2;
    return COL1;
}

bool is_bipartite(const graph_t& graph, colors_t& colors, std::vector<bool>& visited, std::int8_t vertex, color_t color) {
    if (colors[vertex] != NOCOL && colors[vertex] != color) {
        return false;
    }
    colors[vertex] = color;
    visited[vertex] = true;
    for (std::int8_t v : graph[vertex]) {
        if (!visited[v]) {
            if (!is_bipartite(graph, colors, visited, v, i_color(color))) {
                return false;
            }
        } else {
            if (colors[v] != i_color(color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    graph_t graph(n);
    colors_t colors(n, NOCOL);
    std::vector<bool> visited(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        graph[x].insert(static_cast<std::int8_t>(y));
        graph[y].insert(static_cast<std::int8_t>(x));
    }
    for (std::int8_t v = 0; v < n; v++) {
        if (!visited[v]) {
            if (!is_bipartite(graph, colors, visited, v, COL1)) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}
