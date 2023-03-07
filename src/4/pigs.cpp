//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>
#include <unordered_set>

typedef std::vector<std::unordered_set<int>> graph_t;

void dfs(const graph_t& graph, std::vector<bool>& visited, int vert) {
    visited[vert] = true;
    for (int next_vert: graph[vert]) {
        if (!visited[next_vert]) {
            dfs(graph, visited, next_vert);
        }
    }
}

int main() {
    int n, comp = 0;
    std::cin >> n;
    graph_t graph(n);
    std::vector<bool> visited(n);
    // read graph
    for (int key = 0; key < n; key++) {
        int value;
        std::cin >> value;
        value--;
        if (key != value) {
            graph[key].insert(value);
            graph[value].insert(key);
        }
    }
    // find components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            comp++;
        }
    }
    std::cout << comp << std::endl;
    return 0;
}
