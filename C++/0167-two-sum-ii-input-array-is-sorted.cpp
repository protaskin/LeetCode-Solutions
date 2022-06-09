class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, const int target) {
    	int l = 0;
    	int r = numbers.size() - 1;

    	while (true) {
    		const int sum = numbers[l] + numbers[r];
    		if (sum > target) {
    			--r;
    		} else if (sum < target) {
    			++l;
    		} else {
    			return {l + 1, r + 1}; // 1-indexed
    		}
    	}
    }
};
