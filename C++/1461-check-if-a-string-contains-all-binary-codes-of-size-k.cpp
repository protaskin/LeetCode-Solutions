class Solution {
public:
    bool hasAllCodes(const string s, const int k) {
        const int n = s.size();
        if (k >= n) {
            return false;
        }

        int need = 1 << k;
        const uint32_t mask = need - 1;
        vector<bool> found(need);

        uint32_t window = 0;
        for (int i = 0, j = k - 1; i < k; ++i) {
            window |= (s[i] == '1') << (j - i);
        }

        found[window] = true;
        --need;

        for (int i = k; i < n; ++i) {
            window <<= 1;
            window &= mask;
            window |= (s[i] == '1');
            if (!found[window]) {
                found[window] = true;
                if (--need == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};
