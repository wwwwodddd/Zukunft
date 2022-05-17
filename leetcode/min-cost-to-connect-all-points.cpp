class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<int> d(n, 1e9);
        vector<int> v(n);
        d[0] = 0;
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            int mind = 1e9, k = -1;
            for (int j = 0; j < n; j++)
            {
                if (!v[j])
                {
                    if (mind > d[j])
                    {
                        mind = d[j];
                        k = j;
                    }
                }
            }
            z += mind;
            v[k] = 1;
            for (int j = 0; j < n; j++)
            {
                if (!v[j])
                {
                    d[j] = min(d[j], abs(p[j][0] - p[k][0]) + abs(p[j][1] - p[k][1]));
                }
            }
        }
        return z;
    }
};