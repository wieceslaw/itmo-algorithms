//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef enum {
    NOCOL = 0,
    COL1 = 1,
    COL2 = 2
} color_t;

int n, m;
color_t colors[100];
bool visited[100];
unordered_set<char> graph[100];

inline color_t i_color(color_t color) {
    if (color == COL1)
        return COL2;
    return COL1;
}

bool dfs(int vertex, color_t color) {
    if (colors[vertex] != NOCOL && colors[vertex] != color) {
        return false;
    }
    colors[vertex] = color;
    visited[vertex] = true;
    for (char v : graph[vertex]) {
        if (!visited[v]) {
            if (!dfs(v, i_color(color))) {
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

void solve() {
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            if (!dfs(v, COL1)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

void read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].insert(char(y));
        graph[y].insert(char(x));
    }
}

int main() {
    read();
    solve();
    return 0;
}
