class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int z = -1e9;
        for (int i: nums)
        {
            z = max(z, s = max(s, 0) + i);
        }
        return z;
    }
};