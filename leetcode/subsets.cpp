class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >re;
        for (int i = 0; i < 1 << nums.size(); i++) {
            vector<int> tmp;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    tmp.push_back(nums[j]);
                }
            }
            re.push_back(tmp);
        }
        return re;
    }
};