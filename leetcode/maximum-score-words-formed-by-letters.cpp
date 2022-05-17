class Solution {
public:
    vector<int> c;
    vector<string> w;
    vector<int> s;
    int z;
    void dfs(int x, int y)
    {
        z = max(z, y);
        if (x == w.size())
        {
            return;
        }
        dfs(x + 1, y);
        int f = 1;
        for (int i = 0; i < w[x].size(); i++)
        {
            if (--c[w[x][i] - 'a'] < 0)
            {
                f = 0;
            }
            y += s[w[x][i] - 'a'];
        }
        if (f)
        {
            dfs(x + 1, y);
        }
        for (int i = 0; i < w[x].size(); i++)
        {
            c[w[x][i] - 'a']++;
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        w = words;
        s = score;
        c.resize(26);
        z = 0;
        for (char i: letters)
        {
            c[i - 'a']++;
        }
        dfs(0, 0);
        return z;
    }
};