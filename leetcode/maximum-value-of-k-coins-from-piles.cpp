class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        vector<int> f(k + 1);
        for (auto a : p)
        {
            for (int i = k; i >= 0; i--)
            {
                int s = 0;
                for (int j = 1; j <= a.size() && i + j <= k; j++)
                {
                    s += a[j - 1];
                    f[i + j] = max(f[i + j], f[i] + s);
                }
            }
        }
        return f.back();
    }
};