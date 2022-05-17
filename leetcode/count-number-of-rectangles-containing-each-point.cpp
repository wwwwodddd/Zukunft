class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        vector<array<int, 3> > a;
        for (int i = 0; i < r.size(); i++)
        {
            a.push_back({r[i][0], r[i][1], int(p.size())});
        }
        for (int i = 0; i < p.size(); i++)
        {
            a.push_back({p[i][0], p[i][1], i});
        }
        vector<int> z;
        z.resize(p.size());
        vector<int> s(101);
        sort(a.begin(), a.end());
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i][2] == p.size())
            {
                for (int j = 0; j <= a[i][1]; j++)
                {
                    s[j]++;
                }
            }
            else
            {
                z[a[i][2]] = s[a[i][1]];
            }
        }
        return z;
    }
};