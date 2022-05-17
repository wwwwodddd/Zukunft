class Solution {
public:
    vector<vector<int> > a;
    vector<bool> h;
    int z = 0;
    int dfs(int x, int y)
    {
        int s = h[x];
        for (int i : a[x])
        {
            if (i != y)
            {
                int t = dfs(i, x);
                if (t)
                {
                    z++;
                }
                s += t;
            }
        }
        return s;
    }
    int minTime(int n, vector<vector<int>>& e, vector<bool>& hasApple) {
        a.resize(n);
        h = hasApple;
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0]].push_back(e[i][1]);
            a[e[i][1]].push_back(e[i][0]);
        }
        dfs(0, -1);
        return z * 2;
    }
};