//
// Created by wieceslaw on 21.02.23.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.141592653589
#endif

struct point {
    int x, y, n;
    double a, r;
};

bool compare(point rhs, point lhs) {
    if (rhs.a == lhs.a) {
        return rhs.r < lhs.r;
    }
    return rhs.a < lhs.a;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<point> points(n - 1);
    int x0, y0;
    std::cin >> x0 >> y0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        points[i].a = std::atan2(y - y0, x - x0);
        points[i].n = i + 2;
        points[i].x = x - x0;
        points[i].y = y - y0;
        points[i].r = std::sqrt(((x - x0) * (x - x0)) + ((y - y0) * (y - y0)));
    }
    std::sort(points.begin(), points.end(), compare);
    int last = 0;
    for (int i = 1; i < n - 1; i++) {
        // TODO: remake
        point p1 = points[i], p2 = points[i+1];
        int x = p1.x * p2.y - p1.y * p2.x;
        int d = p1.x * p2.x + p1.y * p2.y;
        if(x < 0 || x == 0 && d < 0) {
            last = i + 1;
            break;
        }
    }
    std::cout << n << '\n';
    std::cout << 1 << '\n';

    for (int i = 0; i < n - 1; i++) {
        std::cout << points[(i + last) % (n - 1)].n << '\n';
    }

    return 0;
}
