class Solution {
public:
    int minimumTotal(const vector<vector<int>>& triangle) {
        auto sums = triangle.back();
        const int n = triangle.size();
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                sums[j] = triangle[i][j] + min(sums[j], sums[j + 1]);
            }
        }

        return sums[0];
    }
};
