class Solution {
public:
    int equalCountSubstrings(string s, int c) {
        int n = s.size();
        vector<vector<int> > a(n + 1, vector<int>(26, 0));
        int z = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = a[i - 1];
            a[i][s[i - 1] - 'a']++;
            for (int j = c; j <= i && j <= 26 * c; j += c)
            {
                int f = 1;
                for (int k = 0; k < 26; k++)
                {
                    if (a[i][k] - a[i - j][k] != 0 && a[i][k] - a[i - j][k] != c)
                    {
                        f = 0;
                        break;
                    }
                }
                z += f;
            }
        }
        return z;
    }
};