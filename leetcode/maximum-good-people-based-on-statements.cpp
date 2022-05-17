class Solution {
public:
    int maximumGood(vector<vector<int>>& a) {
        int n = a.size();
        int z = 0;
        for (int i = 0; i < 1 << n; i++)
        {
            bool f = true;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if ((i >> k & 1) != a[j][k] && a[j][k] < 2)
                        {
                            f = false;
                        }
                    }
                }
            }
            if (f)
            {
                z = max(z, __builtin_popcount(i));
            }
        }
        return z;
    }
};