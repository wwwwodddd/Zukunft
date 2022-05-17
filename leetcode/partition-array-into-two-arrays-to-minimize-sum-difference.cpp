class Solution {
public:
    void gao(vector<int> a, vector<vector<int> > &A)
    {
        int n = a.size();
        A.resize(n + 1);
        for (int i = 0; i < 1 << n; i++)
        {
            int c = 0;
            int s = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    s += a[j];
                    c++;
                }
                else
                {
                    s -= a[j];
                }
            }
            A[c].push_back(s);
        }
        for (int i = 0; i <= n; i++)
        {
            sort(A[i].begin(), A[i].end());
        }
    }
    int minimumDifference(vector<int>& a) {
        int n = a.size() / 2;
        vector<int> l;
        vector<int> r;
        for (int i = 0; i < 2 * n; i++)
        {
            if (i & 1)
            {
                l.push_back(a[i]);
            }
            else
            {
                r.push_back(a[i]);
            }
        }
        vector<vector<int> > L;
        vector<vector<int> > R;
        gao(l, L);
        gao(r, R);
        int z = 1e9;
        for (int i = 0; i <= n; i++)
        {
            int j1 = 0;
            int j2 = 0;
            while (j1 < L[i].size() && j2 < R[i].size())
            {
                z = min(z, abs(L[i][j1] - R[i][j2]));
                if (L[i][j1] < R[i][j2])
                {
                    j1++;
                }
                else
                {
                    j2++;
                }
            }
        }
        return z;
    }
};