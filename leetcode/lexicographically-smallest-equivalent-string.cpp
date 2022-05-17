class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    string smallestEquivalentString(string s, string t, string b) {
        f.resize(256);
        for (int i = 0; i < 256; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < s.size(); i++)
        {
            int x = F(s[i]);
            int y = F(t[i]);
            if (x > y)
            {
                swap(x, y);
            }
            f[y] = x;
        }
        for (int i = 0; i < b.size(); i++)
        {
            b[i] = F(b[i]);
        }
        return b;
    }
};