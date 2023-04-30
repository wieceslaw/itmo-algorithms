//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

#define MAX_SIZE 1000

using namespace std;

int n, counter, only_scc;
int max_tank, min_tank;
int ind[MAX_SIZE];
int low[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];
queue<int> st;

void dfs(int max_size, int v) {
    ind[v] = low[v] = ++counter;
    st.push(v);
    for (int u = 0; u < n; u++) {
        if (v != u && graph[v][u] <= max_size) {
            if (ind[u] == 0) {
                dfs(max_size, u);
            }
            if (ind[u] != 0) {
                ind[v] = min(ind[v], ind[u]);
            }
        }
    }
    if (ind[v] == low[v]) {
        if (st.size() != n || st.front() != v) {
            only_scc = false;
        }
    }
}

bool is_connected(int max_size) {
    std::fill(std::begin(ind), std::end(ind), 0);
    std::fill(std::begin(low), std::end(low), 0);
    st = queue<int>();
    counter = 0;
    only_scc = true;
    dfs(max_size, 0);
    return only_scc;
}

int binary_search() {
    int l = min_tank;
    int r = max_tank;
    while (l < r) {
        int m = (l + r) / 2;
        bool result = is_connected(m);
        if (result) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void solve() {
    cout << binary_search() << endl;
}

void read() {
    std::cin >> n;
    max_tank = 0;
    min_tank = INT32_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] > max_tank) {
                max_tank = graph[i][j];
            }
            if (graph[i][j] < min_tank) {
                min_tank = graph[i][j];
            }
        }
    }
}

int main() {
    read();
    solve();
    return 0;
}
