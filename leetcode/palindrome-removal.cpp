class Solution {
public:
    int minimumMoves(vector<int>& a) {
        int n = a.size();
        vector<vector<int> > f(n, vector<int>(n, n));
        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;                
                if (a[i] == a[j])
                {
                    if (j - i <= 1)
                    {
                        f[i][j] = 1;
                    }
                    else
                    {
                        f[i][j] = min(f[i][j], f[i + 1][j - 1]);                    
                    }
                }
                for (int k = i; k < j; k++)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
};