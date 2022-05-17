class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m, ans;
    void dfs(const vector<vector<int>>& grid, vector<vector<bool> > &vis, int x, int y, int left) {
        vis[x][y] = true;
        if (grid[x][y] == 2) {
            if (left == 1) {
                ans++;
            }
        } else {
            for (int k = 0; k < 4; k++) {
                int nextx = x + dx[k];
                int nexty = y + dy[k];
                if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m) {
                    if (!vis[nextx][nexty] && grid[nextx][nexty] != -1) {
                        dfs(grid, vis, nextx, nexty, left-1);
                    }
                }
            }
        }
        vis[x][y] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        int startx = -1;
        int starty = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    cnt++;
                }
                if (grid[i][j] == 1) {
                    startx = i;
                    starty = j;
                }
            }
        }
        ans = 0;
        vector<vector<bool> > vis;
        vis.resize(n);
        for (int i = 0; i < n; i++) {
            vis[i].resize(m);
        }
        dfs(grid, vis, startx, starty, cnt);
        return ans;
    }
};