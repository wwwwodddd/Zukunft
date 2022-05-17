class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        bitset<1000> a[1000];
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0]][e[i][1]] = 1;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][k])
                {
                    a[i] |= a[k];
                }
            }
        }
        vector<vector<int> > z;
        for (int i = 0; i < n; i++)
        {
            vector<int> b;
            for (int j = 0; j < n; j++)
            {
                if (a[j][i])
                {
                    b.push_back(j);
                }
            }
            z.push_back(b);
        }
        return z;
    }
};