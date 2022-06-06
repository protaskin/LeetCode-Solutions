class Solution {
public:
    vector<int> runningSum(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            result[i] = sum += nums[i];
        }

        return result;
    }
};
