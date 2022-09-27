#pragma once
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define LINE_SIZE 5

namespace Bingo {
    struct Table {
        vector<vector<pair<int, bool>>> data;
        vector<int> found_rows;
        vector<int> found_cols;
        bool has_won;
        Table();
        Table(vector<vector<int>> data);
        int max_rows();
        int max_cols();
        int get_winner();
        int update(int target);
    };

    vector<int> get_extracted();
    vector<Table> get_table();
    int update(vector<Table> *table, int n);
}