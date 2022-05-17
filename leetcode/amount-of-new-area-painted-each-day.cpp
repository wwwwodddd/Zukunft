class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    vector<int> amountPainted(vector<vector<int>>& p) {
        vector<int> z(p.size());
        f.resize(50001);
        for (int i = 0; i < f.size(); i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < p.size(); i++)
        {
            for (int j = F(p[i][0]); j < p[i][1]; j = F(j))
            {
                z[i]++;
                f[j] = j + 1;
            }
        }
        return z;
    }
};