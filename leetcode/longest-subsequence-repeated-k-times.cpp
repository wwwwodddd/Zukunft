class Solution {
public:
    vector<int> c;
    string z;
    string s;
    int k;
    bool good(string t)
    {
        int j = 0;
        for (char i: s)
        {
            if (i == t[j % t.size()])
            {
                j++;
            }
        }
        return j >= k * t.size();
    }
    void dfs(string t)
    {
        if (z.size() < t.size() || z.size() == t.size() && z < t)
        {
            z = t;
        }
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > 0 && good(t + char('a' + i)))
            {
                c[i]--;
                dfs(t + char('a' + i));
                c[i]++;
            }
        }
    }
    string longestSubsequenceRepeatedK(string ss, int kk) {
        s = ss;
        k = kk;
        c.resize(26);
        for (char i: s)
        {
            c[i - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            c[i] /= k;
        }
        dfs("");
        return z;
    }
};