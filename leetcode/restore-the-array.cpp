class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int p = 1000000007;
        int n = s.size();
        vector<int> f;
        f.resize(n + 1);
        f[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0')
            {
                int j = i;
                long long t = 0;
                while (j < n)
                {
                    t = t * 10 + s[j++] - '0';
                    if (t > k)
                    {
                        break;
                    }
                    f[j] = (f[j] + f[i]) % p;
                }
            }
        }
        return f[n];
    }
};