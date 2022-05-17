class Solution {
public:
    vector<vector<pair<int, int> > > a;
    int z;
    void dfs(int x, int y)
    {
        for (pair<int, int> i: a[x])
        {
            if (i.first != y)
            {
                z += i.second;
                dfs(i.first, x);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& e) {
        a.resize(n);
        z = 0;
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][1]].push_back(make_pair(e[i][0], 0));
            a[e[i][0]].push_back(make_pair(e[i][1], 1));
        }
        dfs(0, -1);
        return z;
    }
};