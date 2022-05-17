class Solution {
public:
    int n;
    vector<int> v;
    vector<vector<int> > b;
    int dfs(int j)
    {
        v[j] = 1;
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0 && (long long)(b[i][0]-b[j][0]) * (b[i][0]-b[j][0]) + (long long)(b[i][1]-b[j][1]) * (b[i][1]-b[j][1]) <= (long long)b[j][2] * b[j][2])
            {
                c += dfs(i);
            }
        }
        return c;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        b = bombs;
        n = b.size();
        int z = 0;
        v.resize(n);
        for (int i = 0; i < n; i++)
        {
            fill(v.begin(), v.end(), 0);
            z = max(z, dfs(i));
        }
        return z;
    }
};