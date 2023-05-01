//
// Created by wieceslaw on 19.03.23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#define ABSENT -1

using namespace std;


int n, m, s;
double y;
vector<double> rates[100][100];
vector<double> comms[100][100];
double dist[100];
int pred[100];

double weight(int from, double to_comm, double to_rate) {
    return (dist[from] + to_comm) * to_rate;
}

bool check() {
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            if (!rates[v][u].empty()) {
                for (int k = 0; k < rates[v][u].size(); k++) {
                    double to_comm = comms[v][u][k];
                    double to_rate = rates[v][u][k];
                    double new_weight = weight(v, to_comm, to_rate);
                    if (new_weight < dist[u]) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
                        if (new_weight < dist[u]) {
                            dist[u] = new_weight;
                            pred[u] = v;
                        }
                    }
                }
            }
        }
    }
    if (check()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void read() {
    int a, b;
    double rab, cab, rba, cba;
    cin >> n >> m >> s >> y;
    s--;
    y = -y;
    fill(begin(dist), end(dist), numeric_limits<double>::infinity());
    fill(begin(pred), end(pred), ABSENT);
    dist[s] = y;
    for (int i = 0; i < m; i++) {
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
