class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 2 >= nums.size() || nums[i + 2] != nums[i]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};