

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int idx = max_element(nums.begin(), nums.end()) - nums.begin();
		for (int i = 0; i < nums.size(); i++) {
			if (i == idx) {
				continue;
			}
			if (nums[i] * 2 > nums[idx]) {
				return -1;
			}
		}
		return idx;
	}
};