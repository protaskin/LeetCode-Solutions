class NumMatrix {
public:
    NumMatrix(const vector<vector<int>>& matrix)
        : sums(matrix.size() + 1, vector<int>(matrix[0].size() + 1))
    {
        const int m = matrix.size();
        const int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(const int row1, const int col1, const int row2, const int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }

private:
    vector<vector<int>> sums;
};
