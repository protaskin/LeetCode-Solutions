struct Constraints {
    uint32_t colons;
    uint32_t ldiags;
    uint32_t rdiags;
};

class Solution {
public:
    int totalNQueens(const int n) {
        constexpr int MAX_N = 8;
        int result = 0;
        vector<string> board(n, string(n, '.'));
        const function<void(int, const Constraints&)> solve = [&](const int row, const Constraints& constraints) {
            if (row == n) {
                ++result;
                return;
            }

            for (int col = 0; col < n; ++col) {
                if (
                    constraints.colons & (1 << col) ||
                    constraints.ldiags & (1 << (col + row)) ||
                    constraints.rdiags & (1 << (col - row + MAX_N))
                ) {
                    continue;
                }

                board[row][col] = 'Q';

                solve(row + 1, {
                    constraints.colons | (1 << col),
                    constraints.ldiags | (1 << (col + row)),
                    constraints.rdiags | (1 << (col - row + MAX_N))
                });

                board[row][col] = '.';
            }
        };

        solve(0, {});
        return result;
    }
};
