//
// Created by wieceslaw on 08.02.23.
//
#include <iostream>
#include <stack>
#include <vector>

bool same_l_u(char c1, char c2) {
    if (c1 >= 'A' && c1 <= 'Z') {
        if (c2 >= 'a' && c2 <= 'z') {
            if (c2 - 'a' == c1 - 'A') {
                return true;
            }
        }
    } else {
        if (c2 >= 'A' && c2 <= 'Z') {
            if (c2 - 'A' == c1 - 'a') {
                return true;
            }
        }
    }
    return false;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    char c;
    int a_count = 0, c_count = 0;
    std::stack<char> s;
    std::stack<int> a_s;
    std::stack<int> c_s;
    std::vector<int> ans;
    while (std::cin >> c) {
        if (c >= 'A' && c <= 'Z') {
            c_count++;
            c_s.push(c_count);
            ans.push_back(0);
        }
        if (c >= 'a' && c <= 'z') {
            a_count++;
            a_s.push(a_count);
        }
        if (s.empty()) {
            s.push(c);
        } else {
            if (same_l_u(s.top(), c)) {
                ans[c_s.top() - 1] = a_s.top();
                c_s.pop();
                a_s.pop();
                s.pop();
            } else {
                s.push(c);
            }
        }
    }
    if (s.empty()) {
        std::cout << "Possible \n";
        for (int el : ans) {
            std::cout << el << ' ';
        }
    } else {
        std::cout << "Impossible";
    }
}
