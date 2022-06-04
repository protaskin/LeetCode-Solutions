class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int n = words.size();
        vector<uint32_t> bitsets(n);

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (const char c : words[i]) {
                bitsets[i] |= 1 << (c - 'a');
                if (bitsets[i] == (1 << 26) - 1) {
                    goto contin;
                }
            }

            for (int j = 0; j < i; ++j) {
                if ((bitsets[i] & bitsets[j]) == 0) {
                    result = max(result, static_cast<int>(words[i].size() * words[j].size()));
                }
            }

            contin:;
        }

        return result;
    }
};
