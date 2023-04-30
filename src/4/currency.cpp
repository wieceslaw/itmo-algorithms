//
// Created by wieceslaw on 19.03.23.
//

#include <iostream>

using namespace std;

// todo: can be different exchange points for same currency pair

int n, m, s;
double v;
//double rates[100][100];
//double comms[100][100];

void solve() {

}

void read() {
    int a, b;
    double rab, cab, rba, cba;
    cin >> n >> m >> s >> v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> rab >> cab >> rba >> cba;
        a--, b--;
//        rates[a][b] = rab;
//        rates[b][a] = rba;
//        comms[a][b] = cab;
//        comms[b][a] = cba;
    }
}

int main() {
    read();
    solve();
    return 0;
}
