#include <iostream>
#include <vector>
#include <cassert>
#include "Bingo.hpp"

void first_star(std::vector<int> winners) {
    assert(winners.size() > 0);
    std::cout << winners[0] << std::endl;
}

void second_star(std::vector<int> winners) {
    int size = winners.size();
    assert(size > 0);
    std::cout << winners[size - 1] << std::endl;
}

int main() {
    std::vector<int> extractions = Bingo::get_extracted();
    std::vector<Bingo::Table> bingo_table = Bingo::get_table();
    std::vector<int> wins(0);
    for (auto num : extractions) {
        int res = Bingo::update(&bingo_table, num);
        if (res > 0) {
            wins.push_back(res);
        }
    }
    first_star(wins);
    second_star(wins);
    return 0;
}