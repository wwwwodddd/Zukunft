class Solution {
public:
    int maxStudents(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> s;
        for (int i = 0; i < 1 << m; i++)
        {
            if ((i & (i >> 1)) == 0)
            {
                s.push_back(i);
            }
        }
        vector<vector<int> > f(n + 1, vector<int>(s.size(), 0));
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            int b = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '#')
                {
                    b |= 1 << j;
                }
            }
            for (int j = 0; j < s.size(); j++)
            {
                if ((s[j] & b) == 0)
                {
                    for (int k = 0; k < s.size(); k++)
                    {
                        if ((s[j] & (s[k] >> 1)) == 0 && (s[j] & (s[k] << 1)) == 0)
                        {
                            f[i+1][j] = max(f[i+1][j], f[i][k] + __builtin_popcount(s[j]));
                            z = max(z, f[i+1][j]);
                        }
                    }
                }
            }
        }
        return z;
    }
};