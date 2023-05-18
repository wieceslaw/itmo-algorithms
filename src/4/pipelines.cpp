//
// Created by wieceslaw on 19.03.23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s, f;
vector<vector<int>> gg;
vector<vector<int>> i_gg;
int g[500][500];
int longest[500];
bool used[500];
vector<int> t;

void dfs(int v) {
    used[v] = true;
    if (v != f) {
        for (int u : gg[v]) {
            i_gg[u].push_back(v);
            if (!used[u]) {
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
        for (int u : i_gg[v]) {
            longest[v] = max(longest[v], longest[u] + g[u][v]);
        }
    }
    cout << longest[f] << endl;
}

void read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    gg = vector<vector<int>>(n);
    i_gg = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        gg[a].push_back(b);
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