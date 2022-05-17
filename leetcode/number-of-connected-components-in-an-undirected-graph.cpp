class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    int countComponents(int n, vector<vector<int>>& e) {
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < e.size(); i++)
        {
            if (F(e[i][0]) != F(e[i][1]))
            {
                n--;
            }
            f[F(e[i][0])] = F(e[i][1]);
        }
        return n;
    }
};