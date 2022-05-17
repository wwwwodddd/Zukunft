class Solution {
public:
    vector<vector<int> > g;
    vector<vector<int> > d;
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool in(int x, int y)
    {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    bool fuck(int M)
    {
        vector<vector<int> > e(n, vector<int>(m, -1));
        queue<pair<int, int> > q;
        e[0][0] = M;
        q.push(make_pair(0, 0));
        while (q.size())
        {
            pair<int, int> u = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = u.first + dx[k];
                int ny = u.second + dy[k];
                if (in(nx, ny) && e[nx][ny] == -1 && e[u.first][u.second] + 1 <= d[nx][ny] && g[nx][ny] != 2)
                {
                    if (nx == n - 1 && ny == m - 1)
                    {
                        return true;
                    }
                    if (e[u.first][u.second] + 1 < d[nx][ny])
                    {
                        e[nx][ny] = e[u.first][u.second] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();
        d = g;
        queue<pair<int, int> > q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                d[i][j] = 0x3f3f3f3f;
                if (g[i][j] == 1)
                {
                    d[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (q.size())
        {
            pair<int, int> u = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = u.first + dx[k];
                int ny = u.second + dy[k];
                if (in(nx, ny) && d[nx][ny] == 0x3f3f3f3f && g[nx][ny] != 2)
                {
                    d[nx][ny] = d[u.first][u.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << d[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int L = -1;
        int R = 1e9 + 1;
        while (L < R - 1)
        {
            int M = (L + R) / 2;
            if (fuck(M))
            {
                L = M;
            }
            else
            {
                R = M;
            }
        }
        return L;
    }
};