//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<short int, short int> point_t;
typedef int64_t ll;
auto compare = [](pair<ll, point_t> p1, pair<ll, point_t> p2) {
    return p1.first > p2.first;
};

short int n, m, x1, y1, x2, y2;
point_t s, d;
short int map[1000][1000];
bool visited[1000][1000];
ll dist[1000][1000];
point_t pred[1000][1000];
priority_queue<pair<ll, point_t>, vector<pair<ll, point_t>>, decltype(compare)> p_queue(compare);

char convert(char c) {
    if (c == '.') {
        return 1;
    } else if (c == 'W') {
        return 2;
    } else {
        return 0;
    }
}

vector<point_t> points_near(point_t v) {
    vector<point_t> result;
    // + 0
    if ((v.first + 1) >= 0 &&
        (v.first + 1) < n) {
        result.emplace_back(v.first + 1, v.second);
    }
    // - 0
    if ((v.first - 1) >= 0 &&
        (v.first - 1) < n) {
        result.emplace_back(v.first - 1, v.second);
    }
    // 0 +
    if ((v.second + 1) >= 0 &&
        (v.second + 1) < m) {
        result.emplace_back(v.first, v.second + 1);
    }
    // 0 -
    if ((v.second - 1) >= 0 &&
        (v.second - 1) < m) {
        result.emplace_back(v.first, v.second - 1);
    }
    return result;
}

void print_path() {
    // restore path
    vector<point_t> path;
    point_t last = d;
    while (last != s) {
        path.push_back(last);
        last = pred[last.first][last.second];
    }
    path.push_back(s);

    // print path
    for (auto rit = path.rbegin(); rit != path.rend(); rit++) {
        auto next_i = next(rit);
        if (next_i == path.rend()) {
            break;
        }
        point_t i = *rit;
        point_t j;
        j = *next_i;
        if (i.first == j.first) {
            if (i.second > j.second) {
                cout << 'W';
            } else {
                cout << 'E';
            }
        } else {
            if (i.first > j.first) {
                cout << 'N';
            } else {
                cout << 'S';
            }
        }
    }
}

void dijkstra() {
    do {
        point_t v;
        do {
            v = p_queue.top().second;
            p_queue.pop();
        } while (visited[v.first][v.second] && !p_queue.empty());
        if (v == d) {
            cout << dist[v.first][v.second] << endl;
            return;
        }
        for (point_t &u: points_near(v)) {
            if (!visited[u.first][u.second]) {
                ll *u_dist = &dist[u.first][u.second];
                ll add_dist = map[u.first][u.second];
                if (add_dist == 0) {
                    continue;
                }
                ll new_dist = dist[v.first][v.second] + add_dist;
                if (new_dist < *u_dist) {
                    pred[u.first][u.second] = v;
                    *u_dist = new_dist;
                }
                p_queue.emplace(*u_dist, u);
            }
        }
        visited[v.first][v.second] = true;
    } while (!p_queue.empty());
    cout << -1 << endl;
}

void solve() {
    if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        return;
    }
    dijkstra();
    print_path();
}

void read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    s = {x1, y1};
    d = {x2, y2};
    fill_n(&dist[0][0], 1000 * 1000, INT64_MAX);
    dist[x1][y1] = 0;
    p_queue.emplace(0, s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            map[i][j] = convert(tmp);
        }
    }
}

int main() {
    read();
    solve();
    return 0;
}
