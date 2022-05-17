class NumMatrix {
public:
    vector<vector<int> > c;
    vector<vector<int> > b;
    int n, m;
    NumMatrix(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        c.resize(n + 1);
        b = a;
        for (int i = 0; i <= n; i++)
        {
            c[i].resize(m + 1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c[i + 1][j + 1] = a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j + (j & -j) <= m)
                {
                    c[i][j + (j & -j)] += c[i][j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i + (i & -i) <= n)
                {
                    c[i + (i & -i)][j] += c[i][j];
                }
            }
        }
    }
    
    void update(int x, int y, int z) {
        x++;
        y++;
        for (int i = x; i <= n; i += i & -i)
        {
            for (int j = y; j <= m; j += j & -j)
            {
                c[i][j] += z - b[x - 1][y - 1];
            }
        }
        b[x - 1][y - 1] = z;
    }
    int query(int x, int y)
    {
        int z = 0;
        for (int i = x; i > 0; i -= i & -i)
        {
            for (int j = y; j > 0; j -= j & -j)
            {
                z += c[i][j];
            }
        }
        return z;
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        r2++;
        c2++;
        return query(r2, c2) - query(r2, c1) - query(r1, c2) + query(r1, c1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */