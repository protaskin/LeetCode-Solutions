class Solution {
public:
    int minDeletions(const string_view s) {
        vector<int> freq(27); // One additional element to hold a zero
        for (const char c : s) {
            ++freq[c - 'a'];
        }

        sort(freq.begin(), freq.end(), greater<int>{});

        int result = 0;
        for (int i = 1; freq[i] != 0; ++i) {
            if (freq[i] >= freq[i - 1]) {
                const int prev = freq[i];
                freq[i] = max(0, freq[i - 1] - 1);
                result += prev - freq[i];
            }
        }

        return result;
    }
};
