//
// Created by wieceslaw on 06.03.23.
//

#include <iostream>
#include <vector>
#include <cstddef>
#include <queue>

inline char calc(std::uint8_t c) {
    if (c == '.') {
        return 1;
    } else if (c == 'W') {
        return 2;
    } else {
        return 0;
    }
}

typedef std::uint16_t cord_t;
typedef std::pair<cord_t, cord_t> point_t;
typedef std::int64_t dist_t;
typedef std::vector<std::vector<uint8_t>> map_t;
auto compare = [](std::pair<dist_t, point_t> p1, std::pair<dist_t, point_t> p2) {
    return p1.first > p2.first;
};

std::vector<point_t> near(point_t v, cord_t n, cord_t m) {
    std::vector<point_t> result;
    // + 0
    if ((v.first + 1) >= 0 &&
        (v.first + 1) < n)
    {
        result.emplace_back(v.first + 1, v.second);
    }
    // - 0
    if ((v.first - 1) >= 0 &&
        (v.first - 1) < n)
    {
        result.emplace_back(v.first - 1, v.second);
    }
    // 0 +
    if ((v.second + 1) >= 0 &&
        (v.second + 1) < m)
    {
        result.emplace_back(v.first, v.second + 1);
    }
    // 0 -
    if ((v.second - 1) >= 0 &&
        (v.second - 1) < m)
    {
        result.emplace_back(v.first, v.second - 1);
    }
    return result;
}

dist_t f(point_t v, map_t& map) {
    return static_cast<dist_t>(map[v.first][v.second]);
}

std::vector<point_t> find_path(const std::vector<std::vector<point_t>>& prev, point_t s, point_t d) {
    std::vector<point_t> path;
    point_t last = d;
    while (last != s) {
        path.push_back(last);
        last = prev[last.first][last.second];
    }
    path.push_back(s);
    return path;
}

void print_path(const std::vector<point_t>& path) {
    for (auto rit = path.rbegin(); rit != path.rend(); rit++) {
        auto next = std::next(rit);
        if (next == path.rend()) {
            break;
        }
        point_t i = *rit;
        point_t j;
        j = *next;
        if (i.first == j.first) {
            if (i.second > j.second) {
                std::cout << 'W';
            } else {
                std::cout << 'E';
            }
        } else {
            if (i.first > j.first) {
                std::cout << 'N';
            } else {
                std::cout << 'S';
            }
        }
    }
}

void dijkstra(cord_t n, cord_t m, point_t s, point_t d, map_t& map) {
    if (s == d) {
        std::cout << 0 << std::endl;
        return;
    }

    std::vector<std::vector<dist_t>> dist(n);
    std::vector<std::vector<point_t>> prev(n);
    std::vector<std::vector<bool>> visited(n);
    std::priority_queue<
            std::pair<dist_t, point_t>,
            std::vector<std::pair<dist_t, point_t>>,
            decltype(compare)
            > queue(compare);

    for (cord_t i = 0; i < n; i++) {
        dist[i] = std::vector<dist_t>(m, INT64_MAX);
        prev[i] = std::vector<point_t>(m);
        visited[i] = std::vector<bool>(m);
    }

    dist[s.first][s.second] = 0;
    point_t v;
    queue.emplace(0, s);
    do {
        do {
            v = queue.top().second;
            queue.pop();
        } while (visited[v.first][v.second] && !queue.empty());
        if (v == d) {
            std::cout << dist[v.first][v.second] << std::endl;
            auto path = find_path(prev, s, d);
            print_path(path);
            return;
        }
        for (point_t& u : near(v, n, m)) {
            if (!visited[u.first][u.second]) {
                dist_t* u_dist = &dist[u.first][u.second];
                dist_t add_dist = f(u, map);
                if (add_dist == 0) {
                    // if water
                    continue;
                }
                dist_t new_dist = dist[v.first][v.second] + add_dist;
                if (new_dist < *u_dist) {
                    prev[u.first][u.second] = v;
                    *u_dist = new_dist;
                }
                queue.emplace(*u_dist, u);
            }
        }
        visited[v.first][v.second] = true;
    } while (!queue.empty());
    std::cout << -1 << std::endl;
}

int main() {
    std::uint16_t n, m, x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    map_t map(n);
    for (int i = 0; i < n; i++) {
        map[i] = std::vector<uint8_t>(m);
        for (int j = 0; j < m; j++) {
            char tmp;
            std::cin >> tmp;
            map[i][j] = calc(tmp);
        }
    }
    dijkstra(n, m, {x1, y1}, {x2, y2}, map);
    return 0;
}
