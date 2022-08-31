class Solution {
public:
    int minMoves2(vector<int> nums) {
        const int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        int result = 0;
        for (int i = 0; i < n / 2; ++i) {
            result += nums[(n - 1) - i] - nums[i];
        }

        return result;
    }
};
