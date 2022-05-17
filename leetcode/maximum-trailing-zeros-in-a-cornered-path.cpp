class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<pair<int, int> > > B(n, vector<pair<int, int> >(m));
        vector<vector<pair<int, int> > > L, R, U, D;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                while (a[i][j] % 2 == 0)
                {
                    B[i][j].first++;
                    a[i][j] /= 2;
                }
                while (a[i][j] % 5 == 0)
                {
                    B[i][j].second++;
                    a[i][j] /= 5;
                }
            }
        }
        L = R = U = D = B;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    U[i][j] = make_pair(U[i][j].first + U[i - 1][j].first, U[i][j].second + U[i - 1][j].second);
                }
                if (j > 0)
                {
                    L[i][j] = make_pair(L[i][j].first + L[i][j - 1].first, L[i][j].second + L[i][j - 1].second);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i + 1 < n)
                {
                    D[i][j] = make_pair(D[i][j].first + D[i + 1][j].first, D[i][j].second + D[i + 1][j].second);
                }
                if (j + 1 < m)
                {
                    R[i][j] = make_pair(R[i][j].first + R[i][j + 1].first, R[i][j].second + R[i][j + 1].second);
                }
            }
        }
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                z = max(z, min(L[i][j].first + U[i][j].first - B[i][j].first, L[i][j].second + U[i][j].second - B[i][j].second));
                z = max(z, min(L[i][j].first + D[i][j].first - B[i][j].first, L[i][j].second + D[i][j].second - B[i][j].second));
                z = max(z, min(R[i][j].first + U[i][j].first - B[i][j].first, R[i][j].second + U[i][j].second - B[i][j].second));
                z = max(z, min(R[i][j].first + D[i][j].first - B[i][j].first, R[i][j].second + D[i][j].second - B[i][j].second));
            }
        }
        return z;
    }
};