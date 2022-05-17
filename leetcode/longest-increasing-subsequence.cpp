class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> f(a.size());
        fill(f.begin(), f.end(), 0x3f3f3f3f);
        for (int i: a)
        {
            *lower_bound(f.begin(), f.end(), i) = i;
        }
        return lower_bound(f.begin(), f.end(), 0x3f3f3f3f) - f.begin();
    }
};