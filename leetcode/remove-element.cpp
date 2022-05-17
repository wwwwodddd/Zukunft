class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        nums.erase(lower_bound(nums.begin(), nums.end(), val), upper_bound(nums.begin(), nums.end(), val));
        return nums.size();
    }
};