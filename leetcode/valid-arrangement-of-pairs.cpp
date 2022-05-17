class Solution {
public:
    map<int, vector<int> > a;
    map<int, int> c, d;
    vector<vector<int> > z;
    void dfs(int x)
    {
        for (; c[x] < a[x].size(); )
        {
            int y = a[x][c[x]];
            c[x]++;
            dfs(y);
            z.push_back({x, y});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& e) {
        int m = e.size(), s = -1;
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0]].push_back(e[i][1]);
            d[e[i][0]]++;
            d[e[i][1]]--;
        }
        for (auto i : d)
        {
            if (i.second == 1 || s == -1)
            {
                s = i.first;
            }
        }
        dfs(s);
        reverse(z.begin(), z.end());
        return z;
    }
};