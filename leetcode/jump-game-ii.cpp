class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> f(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            f[i] = 1e9;
        }
        f[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++)
            {
                f[i + j] = min(f[i + j], f[i] + 1);
            }
        }
        return f.back();
    }
};