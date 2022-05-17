class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int t = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[t++] = nums[i];
            }
        }
        while (t < n) {
            nums[t] = 0;
            t++;
        }
    }
};