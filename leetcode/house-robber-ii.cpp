class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int t = 0;
        int z = 0;
        {
            t = nums[0];
            nums[0] = 0;
            vector<int> f(nums.size() + 1);
            vector<int> g(nums.size() + 1);
            for (int i = 0; i < nums.size(); i++)
            {
                f[i + 1] = g[i] + nums[i];
                g[i + 1] = max(g[i], f[i]);
            }
            z = max(z, max(f.back(), g.back()));
            nums[0] = t;
        }
        {
            t = nums[nums.size() - 1];
            nums[nums.size() - 1] = 0;
            vector<int> f(nums.size() + 1);
            vector<int> g(nums.size() + 1);
            for (int i = 0; i < nums.size(); i++)
            {
                f[i + 1] = g[i] + nums[i];
                g[i + 1] = max(g[i], f[i]);
            }
            z = max(z, max(f.back(), g.back()));
            nums[nums.size() - 1] = t;
        }
        return z;
    }
};