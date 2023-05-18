//
// Created by wieceslaw on 19.03.23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

#define MAX_N 100

int n, m, s;
double y;
vector<double> rates[MAX_N][MAX_N];
vector<double> comms[MAX_N][MAX_N];
double dist[MAX_N];

double weight(int from, double to_comm, double to_rate) {
    return (dist[from] - to_comm) * to_rate;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                if (!rates[v][u].empty()) {
                    for (int k = 0; k < rates[v][u].size(); k++) {
                        double to_comm = comms[v][u][k];
                        double to_rate = rates[v][u][k];
                        double new_weight = weight(v, to_comm, to_rate);
                        if (new_weight > dist[u]) {
                            dist[u] = new_weight;
                            if (i == n - 1) {
                                cout << "YES" << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}

void read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double rab, cab, rba, cba;
    cin >> n >> m >> s >> y;
    s--;
    fill(begin(dist), end(dist), -numeric_limits<double>::infinity());
    dist[s] = y;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        a--, b--;
        rates[a][b].push_back(rab);
        rates[b][a].push_back(rba);
        comms[a][b].push_back(cab);
        comms[b][a].push_back(cba);
    }
}

int main() {
    read();
    solve();
    return 0;
}
