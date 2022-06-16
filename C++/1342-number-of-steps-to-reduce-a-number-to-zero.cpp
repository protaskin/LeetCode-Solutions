class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }

        int result = 0;
        while (num != 0) {
            result += 1 + (num & 1);
            num >>= 1;
        }

        return result - 1;
    }
};
