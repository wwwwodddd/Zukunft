class Solution {
public:
    int maxLength(vector<string>& a) {
        vector<int> b(a.size());
        for (int i = 0; i < a.size(); i++)
        {
            for (char c: a[i])
            {
                int j = c - 'a';
                if (b[i] >> j & 1)
                {
                    b[i] = 0;
                    break;
                }
                else
                {
                    b[i] |= 1 << j;
                }
            }
        }
        int z = 0;
        for (int i = 0; i < 1 << b.size(); i++)
        {
            int t = 0;
            for (int j = 0; j < b.size(); j++)
            {
                if (i >> j & 1)
                {
                    if (t & b[j])
                    {
                        t = 0;
                        break;
                    }
                    else
                    {
                        t |= b[j];
                    }
                }
            }
            z = max(z, __builtin_popcount(t));
        }
        return z;
    }
};