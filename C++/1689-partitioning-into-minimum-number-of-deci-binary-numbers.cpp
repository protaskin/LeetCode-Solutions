class Solution {
public:
    int minPartitions(const string_view n) {
        char result = 0;
        for (const char c : n) {
            result = max(result, c);
            if (result == '9') {
                break;
            }
        }

        return result - '0';
    }
};
