class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    int earliestAcq(vector<vector<int>>& e, int n) {
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
        sort(e.begin(), e.end());
        int t = 0;
        for (int i = 0; i < e.size(); i++)
        {
            if (F(e[i][1]) != F(e[i][2]))
            {
                t++;
                if (t == n - 1)
                {
                    return e[i][0];
                }
            }
            f[F(e[i][1])] = F(e[i][2]);
        }
        return -1;
    }
};