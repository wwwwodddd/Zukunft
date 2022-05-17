class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (n >= 3 && nums[i] == nums[n - 3])
            {
            }
            else
            {
                nums[n++] = nums[i];
            }
        }
        nums.resize(n);
        vector<int> v(200001, -1);
        vector<vector<int> > ret;
        for (int i = 0; i < nums.size(); i++)
        {
            v[nums[i] + 100000] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int s = - nums[i] - nums[j];
                if (-100000 <= s && s <= 100000)
                {
                    if (i < v[s + 100000])
                    {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(s);
                        sort(t.begin(), t.end());
                        ret.push_back(t);
                    }
                }
            }
        }
        sort(ret.begin(), ret.end());
        ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
        return ret;
    }
};