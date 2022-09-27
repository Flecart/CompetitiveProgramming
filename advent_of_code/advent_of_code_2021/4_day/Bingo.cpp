#include "Bingo.hpp"
namespace Bingo {
    Table::Table() {}
    Table::Table(vector<vector<int>> data) {
        assert(data.size() > 0);
        assert(data.size() == data[0].size());

        int size = data.size();
        this->has_won = false;
        this->found_rows = vector<int>(size, 0);
        this->found_cols = vector<int>(size, 0);
        this->data = vector<vector<pair<int, bool>>>(size);
        for (int i = 0; i < size; i++) {
            vector<pair<int, bool>> tmp(size);
            for (int j = 0; j < size; j++) {
                tmp[j] = make_pair(data[i][j], false);
            }
            this->data[i] = tmp;
        }
    }
    int Table::max_rows() {
        int max = -1;
        for (auto num : this->found_rows) {
            if (num > max) max = num;
        }
        return max;
    }
    int Table::max_cols() {
        int max = -1;
        for (auto num : this->found_cols) {
            if (num > max) max = num;
        }
        return max;
    }


    int Table::get_winner() {
        if (this->has_won) return -1;
        int ans = -1;
        if (max_rows() == LINE_SIZE || max_cols() == LINE_SIZE) {
            int not_found_sum = 0;
            for (auto row:data) {
                for (auto pair: row) {
                    if (!pair.second) not_found_sum += pair.first;
                }
            }
            ans = not_found_sum;
            this->has_won = true;
        }
        return ans;
    }

    int Table::update(int target) {
        if (this->has_won) return -1;
        int size = data.size(); 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (!data[i][j].second && data[i][j].first == target) {
                    data[i][j].second = true;
                    found_rows[i] += 1;
                    found_cols[j] += 1;
                }
            }
        }
        int winner = get_winner();
        if (winner == -1) return -1;
        else {
            cout << winner << ' ' << target << endl;
            return winner * target;
        }
    }

    vector<int> get_extracted() {
        vector<int> extracted(0);
        int n;
        char virgola;
        cin >> n;
        while (n != -1) {
            cin >> virgola;
            extracted.push_back(n);
            cin >> n;
        }
        return extracted;
    }

    vector<Table> get_table() {
        vector<Table> bingo(0);

        while (true) {
            // Get single table (should make this another func)
            vector<vector<int>> table(LINE_SIZE);
            for (int i = 0; i < LINE_SIZE; i++) {
                for (int j = 0; j < LINE_SIZE; j++) {
                    int tmp;
                    cin >> tmp;
                    if (tmp == -1) return bingo; // bad style, return in a deep nested loop;
                    table[i].push_back(tmp);
                }
            }
            Table t(table);
            bingo.push_back(t);
        }
    }

    int update(vector<Table> *table, int n) {
        int ret = -1;
        bool finished = false; // i am assuming two tables cant finish together
        for (auto &line : (*table) ) {
            int res = line.update(n);
            if (!finished && res > 0) {
                ret = res;
                finished = true;
            }
        }
        return ret;
    }
}