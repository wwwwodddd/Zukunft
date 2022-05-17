class Solution {
public:
    int sumOfFlooredPairs(vector<int>& a) {
        const int p = 1000000007;
        int m = 0;
        for (int i: a)
        {
            m = max(m, i);
        }
        vector<int> c;
        c.resize(m + 2);
        for (int i: a)
        {
            c[i]++;
        }
        for (int i = 1; i <= m; i++)
        {
            c[i] += c[i - 1];
        }
        long long z = 0;
        for (int i = 1; i <= m; i++)
        {
            int d = c[i] - c[i - 1];
            if (d > 0)
            {
                for (int j = 0; j <= m; j += i)
                {
                    z = (z + (long long)j / i * (c[i] - c[i - 1]) * (c[min(j + i - 1, m)] - c[max(j - 1, 0)])) % p;
                }                
            }
        }
        return z;
    }
};