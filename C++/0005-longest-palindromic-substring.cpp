class Solution {
public:
    string longestPalindrome(const string_view s) {
        const int n = s.size();
        const auto expand = [&](int l, int r) -> pair<int, int> {
            do {
                --l;
                ++r;
            } while (l >= 0 && r < n && s[l] == s[r]);

            return {l + 1, r - 1};
        };

        int maxlen = 0;
        string_view result;
        for (int l = 0, r = 0; l < n; l = ++r) {
            for (; r + 1 < n && s[l] == s[r + 1]; ++r);

            const auto [l1, r1] = expand(l, r);
            const int len = r1 - l1 + 1;
            if (len > maxlen) {
                maxlen = len;
                result = s.substr(l1, len);
            }
        }

        return string(result);
    }
};
