class Solution {
public:
    int maxScore(const vector<int>& cardPoints, const int k) {
        int score = 0;
        for (int i = 0; i < k; ++i) {
            score += cardPoints[i];
        }

        int result = score;
        const int n = cardPoints.size();
        for (int i = k - 1; i >= 0; --i) {
            score += cardPoints[i + (n - k)] - cardPoints[i];
            result = max(result, score);
        }

        return result;
    }
};
