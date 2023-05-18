//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> graph[100];
bool visited[100];

void dfs(int v) {
    visited[v] = true;
    for (int u: graph[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

void solve() {
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    cout << components << endl;
}

void read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int key = 0; key < n; key++) {
        int tmp;
        cin >> tmp;
        tmp--;
        if (key != tmp) {
            graph[key].push_back(tmp);
            graph[tmp].push_back(key);
        }
    }
}

int main() {
    read();
    solve();
    return 0;
}
