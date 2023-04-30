//
// Created by wieceslaw on 19.03.23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s, f;
int g[500][500] = {0};
int longest[500] = {0};
bool used[500] = {0};
vector<int> t;

void dfs(int v) {
    used[v] = true;
    if (v != f) {
        for (int u = 0; u < n; u++) {
            if (g[v][u] && !used[u]) {
                dfs(u);
            }
        }
    }
    t.push_back(v);
}

void topological_sort() {
    dfs(s);
    reverse(t.begin(), t.end());
}

void solve() {
    topological_sort();
    if (!used[f]) {
        cout << "No solution";
        return;
    }
    for (int v : t) {
        for (int u : t) {
            if (g[u][v]) {
                longest[v] = max(longest[v], longest[u] + g[u][v]);
            }
        }
    }
    cout << longest[f] << endl;
}

void read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        g[a][b] = c;
    }
    cin >> s >> f;
    s--, f--;
}

int main() {
    read();
    solve();
    return 0;
}