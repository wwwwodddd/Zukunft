class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> f(nums.size() + 1);
        vector<int> g(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            f[i + 1] = g[i] + nums[i];
            g[i + 1] = max(g[i], f[i]);
        }
        return max(f.back(), g.back());
    }
};