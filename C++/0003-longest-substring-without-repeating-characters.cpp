class Solution {
public:
    int lengthOfLongestSubstring(const string s) {
        const int n = s.size();

        array<int, 128> pos; // Assuming that s contains only ASCII characters
        pos.fill(-1);

        int offset = 0;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            const char c = s[i];
            if (pos[c] >= offset) {
                result = max(result, i - offset);
                offset = pos[c] + 1;
            }

            pos[c] = i;
        }

        return max(result, n - offset);
    }
};
