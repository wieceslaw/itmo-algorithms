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
int st_count, st_first_v;
int ind[MAX_SIZE];
int low[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];

void dfs(int max_size, int v) {
    if (!only_scc) {
        return;
    }
    ind[v] = low[v] = ++counter;
    st_count++;
    for (int u = 0; u < n; u++) {
        if (v != u && graph[v][u] <= max_size) {
            if (ind[u] == 0) {
                dfs(max_size, u);
            }
            if (ind[u] != 0) {
                low[v] = min(low[v], low[u]);
            }
        }
    }
    if (ind[v] == low[v] && (st_count != n || st_first_v != v)) {
        only_scc = false;
    }
}

bool is_connected(int max_size) {
    fill(begin(ind), end(ind), 0);
    fill(begin(low), end(low), 0);
    counter = 0;
    st_count = 0;
    st_first_v = 0;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
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
