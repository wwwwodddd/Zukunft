class Solution {
public:
    bool canJump(vector<int>& nums) {
        int z = 0;
        for (int i = 0; i <= z && i < nums.size(); i++)
        {
            z = max(z, i + nums[i]);
        }
        return z >= nums.size() - 1;
    }
};