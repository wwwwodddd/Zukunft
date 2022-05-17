class Solution {
public:
    int z = 0, n;
    vector<int> y, xplusy, xminusy;
    int totalNQueens(int n) {
        this->n=n;
        y.resize(2 * n);
        xplusy.resize(2 * n);
        xminusy.resize(2 * n);
        dfs(0);
        return z;
    }
    void dfs(int x)
    {
        if (x == n)
        {
            z++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!y[i] && !xplusy[x + i] && !xminusy[x - i + n])
            {
                y[i] = xplusy[x + i] = xminusy[x - i + n] = 1;
                dfs(x + 1);
                y[i] = xplusy[x + i] = xminusy[x - i + n] = 0;
            }
        }
        
    }
};