class Solution {
public:
    int countTexts(string s) {
        const int p = 1000000007;
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1];
            if (i >= 2 && s[i - 1] == s[i - 2])
            {
                f[i] = (f[i] + f[i - 2]) % p;
            }
            if (i >= 3 && s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3])
            {
                f[i] = (f[i] + f[i - 3]) % p;
            }
            if (i >= 4 && s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3] && s[i - 3] == s[i - 4] && (s[i - 1] == '7' || s[i - 1] == '9'))
            {
                f[i] = (f[i] + f[i - 4]) % p;
            }
        }
        return f[n];
        
    }
};