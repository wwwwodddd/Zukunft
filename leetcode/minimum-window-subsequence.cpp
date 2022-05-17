class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        vector<vector<int> > f(n + 1);
        f[n].resize(26);
        for (int i = 0; i < 26; i++)
        {
            f[n][i] = n;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            f[i] = f[i + 1];
            f[i][s[i] - 'a'] = i;
        }
        int z = n + 1, zi = 0;
        for (int i = 0; i < n; i++)
        {
            int p = i;
            for (int j = 0; j < t.size(); j++)
            {
                if (f[p][t[j] - 'a'] == n)
                {
                    p = 2 * n;
                    break;
                }
                p = f[p][t[j] - 'a'] + 1;
            }
            if (z > p - i)
            {
                z = p - i;
                zi = i;
            }
        }
        if (z > n)
        {
            return "";
        }
        return s.substr(zi, z);
    }
};