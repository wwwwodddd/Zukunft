class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mxs = 0, mx = nums[0];
        int mns = 0, mn = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            mxs = max(mxs, 0) + nums[i];
            mns = min(mns, 0) + nums[i];
            sum += nums[i];
            mx = max(mx, mxs);
            mn = min(mn, mns);
        }
        if (mx < 0)
        {
            return mx;
        }
        return max(mx, sum - mn);
    }
};
