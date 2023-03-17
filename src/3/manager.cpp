//
// Created by wieceslaw on 04.03.23.
//

#include <iostream>
#include <algorithm>
#include <list>
#include <cstdint>
#include <map>
#include <unordered_map>

struct block_t {
    uint32_t start;
    uint32_t end;
    bool is_free;
};

inline uint32_t block_size(block_t block) {
    return block.end - block.start;
}

auto compare = [](block_t lhs, block_t rhs) {
    if (block_size(lhs) == block_size(rhs)) {
        return lhs.start > rhs.start;
    }
    return block_size(lhs) > block_size(rhs);
};

typedef std::map<block_t, std::list<block_t>::iterator, decltype(compare)> freed_t;
typedef std::unordered_map<int, std::list<block_t>::iterator> alloc_t;


std::list<block_t>::iterator alloc_block(freed_t& freed, alloc_t& alloc, std::list<block_t>& blocks, uint32_t size, int n) {
    if (freed.begin() == freed.end()) {
        return blocks.end();
    }
    auto block_it = freed.begin()->second;
    block_t block = *block_it;
    if (block_size(block) < size) {
        return blocks.end();
    } else if (block_size(block) == size) {
        // remove block: free
        block_it->is_free = false;
        alloc.insert({n, block_it});
        freed.erase(freed.begin());
        return block_it;
    } else {
        // split block: allocated | free
        auto new_block_it = blocks.insert(block_it, {block.start, block.start + size, false});
        block_it->start = block.start + size;
        freed.erase(freed.begin());
        freed.insert({*block_it, block_it});
        alloc.insert({n, new_block_it});
        return new_block_it;
    }
}

void free_block(freed_t& freed, alloc_t& alloc, std::list<block_t>& blocks, int n) {
    auto alloc_it = alloc.find(n);
    if (alloc_it == alloc.end()) { return; }
    auto block_it = alloc_it->second;
    block_it->is_free = true;

    // check left, check right
    bool merge_left = false;
    bool merge_right = false;
    if (block_it != blocks.begin()) {
        auto prev_it = block_it;
        prev_it--;
        if (prev_it->is_free) {
            merge_left = true;
            auto freed_it = freed.find(*prev_it);
            prev_it->end = block_it->end;
            blocks.erase(block_it);
            block_it = prev_it;
            freed.erase(freed_it);
            freed.insert({*block_it, block_it});
        }
    }
    if (block_it != blocks.end()) {
        auto next_it = block_it;
        next_it++;
        if (next_it != blocks.end() && next_it->is_free) {
            merge_right = true;
            if (!merge_left) {
                auto freed_it = freed.find(*next_it);
                next_it->start = block_it->start;
                blocks.erase(block_it);
                freed.erase(freed_it);
                freed.insert({*next_it, next_it});
            } else {
                auto freed_it = freed.find(*block_it);
                block_it->end = next_it->end;
                auto find_it = freed.find(*next_it);
                freed.erase(find_it);
                blocks.erase(next_it);
                freed.erase(freed_it);
                freed.insert({*block_it, block_it});
            }
        }
    }
    if (!merge_left && !merge_right) {
        freed.insert({*block_it, block_it});
    }
}

int main() {
    uint32_t n;
    int m;
    std::cin >> n >> m;
    std::list<block_t> blocks;
    alloc_t alloc;
    freed_t freed(compare);
    blocks.push_front({1, n + 1, true});
    freed.insert({blocks.front(), blocks.begin()});
    for (int i = 1; i <= m; i++) {
        int request;
        std::cin >> request;
        if (request >= 0) {
            auto block_it = alloc_block(freed, alloc, blocks, request, i);
            if (block_it == blocks.end()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << block_it->start << '\n';
            }
        } else {
            free_block(freed, alloc, blocks, -request);
        }
    }
    return 0;
}
