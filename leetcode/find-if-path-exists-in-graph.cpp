class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    bool validPath(int n, vector<vector<int>>& e, int s, int t) {
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < e.size(); i++)
        {
            int x = F(e[i][0]);
            int y = F(e[i][1]);
            f[x] = y;
        }
        return F(s) == F(t);
    }
};