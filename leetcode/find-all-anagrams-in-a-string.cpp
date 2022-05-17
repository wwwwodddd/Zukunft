class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> c(256);
        vector<int> z;
        int d = 0;
        for (int i = 0; i < p.size(); i++)
        {
            d += !c[p[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (c[s[i]] == 0)
            {
                d++;
            }
            --c[s[i]];
            if (c[s[i]] == 0)
            {
                d--;
            }
            if (i >= p.size())
            {
                if (c[s[i - p.size()]] == 0)
                {
                    d++;
                }
                c[s[i - p.size()]]++;
                if (c[s[i - p.size()]] == 0)
                {
                    d--;
                }
            }
            if (d == 0)
            {
                z.push_back(i - p.size() + 1);
            }
        }
        return z;
    }
};