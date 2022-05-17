class Solution {
public:
    int kIncreasing(vector<int>& a, int k) {
        vector<vector<int> > f(k);
        int z = a.size();
        for (int i = 0; i < a.size(); i++)
        {
            int j = i % k;
            if (f[j].size() == 0 || a[i] >= f[j].back())
            {
                f[j].push_back(a[i]);
                z--;
            }
            else
            {
                *upper_bound(f[j].begin(), f[j].end(), a[i]) = a[i];
            }
        }
        return z;
    }
};