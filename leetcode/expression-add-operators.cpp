class Solution {
public:
    vector<string> z;
    string s;
    int t;
    void dfs(int x, string o, long long r, long long p)
    {
        if (x == s.size())
        {
            if (r == t)
            {
                z.push_back(o);
            }
            return;
        }
        long long q = 0;
        for (int i = x; i < s.size(); i++)
        {
            if (i > x && q == 0)
            {
                break;
            }
            q = q * 10 + s[i] - '0';
            if (x == 0)
            {
                dfs(i + 1, o + s.substr(x, i - x + 1), q, q);
            }
            else
            {
                dfs(i + 1, o + "+" + s.substr(x, i - x + 1), r + q, q);
                dfs(i + 1, o + "-" + s.substr(x, i - x + 1), r - q, -q);
                dfs(i + 1, o + "*" + s.substr(x, i - x + 1), r - p + p * q, p * q);
            }
        }
    }
    vector<string> addOperators(string s, int t) {
        this->s = s;
        this->t = t;
        dfs(0, "", 0, 0);
        return z;
    }
};