//
// Created by wieceslaw on 08.02.23.
//

#include <iostream>

void annihilate_pairs(int a[], int i, int j) {
    while (0 != a[i] && 0 != a[j]) {
        std::cout << char ('A' + i) << char ('A' + j) << "- \n";
        a[i]--;
        a[j]--;
    }
}

void create_pairs(int a[], int i, int j, int k) {
    while (k) {
        std::cout << char ('A' + i) << char ('A' + j) << "+ \n";
        a[i]++;
        a[j]++;
        k--;
    }
}

void annihilate_edges(int a[]) {
    for (int cur = 0; cur < 4; cur++) {
        int next = (cur + 1) % 4;
        int top = cur + 4;
        int top_next = next + 4;
        annihilate_pairs(a, cur, next);
        annihilate_pairs(a, cur, top);
        annihilate_pairs(a, top, top_next);
    }
}

void annihilate_diagonals(int a[]) {
    for (int cur = 0; cur < 4; cur++) {
        int diag = (cur + 2) % 4 + 4;
        int next = (cur + 1) % 4;
        int next_top = next + 4;
        if (0 != a[cur] && 0 != a[diag]) {
            int m = std::min(a[cur], a[diag]);
            create_pairs(a, next, next_top, m);
            annihilate_pairs(a, cur, next);
            annihilate_pairs(a, next_top, diag);
        }
    }
}

int main() {
    int a[8];
    int color[8] {0, 1, 0, 1, 1, 0, 1, 0};
    int sm = 0;
    for (int i = 0; i < 8; i++) {
        std::cin >> a[i];
        if (color[i]) {
            sm += a[i];
        } else {
            sm -= a[i];
        }
    }
    if (!sm) {
        annihilate_edges(a);
        annihilate_diagonals(a);
    } else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
}
