class Solution {
public:
    int minimumWhiteTiles(string s, int n, int m) {
        int l = s.size();
        vector<vector<int> > f(n + 1, vector<int>(l + 1, 0));
        vector<int> a(l + 1);
        for (int i = 0; i < l; i++)
        {
            a[i + 1] = a[i] + (s[i] == '1');
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= l; j++)
            {
                f[i][j] = f[i][j - 1];
                int k = max(j - m, 0);
                f[i][j] = max(f[i][j], f[i - 1][k] + (a[j] - a[k]));
            }
        }
        return a[l] - f[n][l];        
    }
};
