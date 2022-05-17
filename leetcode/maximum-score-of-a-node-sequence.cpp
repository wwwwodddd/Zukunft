class Solution {
public:
    int maximumScore(vector<int>& a, vector<vector<int>>& e) {
        int n = a.size();
        vector<vector<pair<int, int> > > b(n);
        for (int i = 0; i < e.size(); i++)
        {
            b[e[i][0]].push_back(make_pair(a[e[i][1]], e[i][1]));
            b[e[i][1]].push_back(make_pair(a[e[i][0]], e[i][0]));
        }
        for (int i = 0; i < n; i++)
        {
            sort(b[i].begin(), b[i].end());
            reverse(b[i].begin(), b[i].end());
        }
        int z = -1;
        for (int i = 0; i < e.size(); i++)
        {
            int x = e[i][0];
            int y = e[i][1];
            int px = -1;
            int vx = -1;
            int vy = -1;
            for (int j = 0; j < b[x].size(); j++)
            {
                if (b[x][j].second != y)
                {
                    vx = b[x][j].first;
                    px = b[x][j].second;
                    break;
                }
            }
            for (int j = 0; j < b[y].size(); j++)
            {
                if (b[y][j].second != x && b[y][j].second != px)
                {
                    vy = b[y][j].first;
                    break;
                }
            }
            if (vx != -1 && vy != -1)
            {
                z = max(z, vx + a[x] + a[y] + vy);
            }
        }
        for (int i = 0; i < e.size(); i++)
        {
            int x = e[i][1];
            int y = e[i][0];
            int px = -1;
            int vx = -1;
            int vy = -1;
            for (int j = 0; j < b[x].size(); j++)
            {
                if (b[x][j].second != y)
                {
                    vx = b[x][j].first;
                    px = b[x][j].second;
                    break;
                }
            }
            for (int j = 0; j < b[y].size(); j++)
            {
                if (b[y][j].second != x && b[y][j].second != px)
                {
                    vy = b[y][j].first;
                    break;
                }
            }
            if (vx != -1 && vy != -1)
            {
                z = max(z, vx + a[x] + a[y] + vy);
            }
        }
        return z;
    }
};