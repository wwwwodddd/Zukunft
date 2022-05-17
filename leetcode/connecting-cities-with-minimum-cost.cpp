class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    int minimumCost(int n, vector<vector<int>>& e) {
        f.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < e.size(); i++)
        {
            swap(e[i][0], e[i][2]);
        }
        sort(e.begin(), e.end());
        int z = 0, t = 0;
        for (int i = 0; i < e.size(); i++)
        {
            if (F(e[i][1]) != F(e[i][2]))
            {
                z += e[i][0];
                t++;
            }
            f[F(e[i][1])] = F(e[i][2]);
        }
        return t == n - 1 ? z : -1;
    }
};