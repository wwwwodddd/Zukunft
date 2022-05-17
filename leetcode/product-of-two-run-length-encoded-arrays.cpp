class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int> > c;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            int t = min(a[i][1], b[j][1]);
            a[i][1] -= t;
            b[j][1] -= t;
            if (c.size() > 0 && a[i][0] * b[j][0] == c[c.size() - 1][0])
            {
                c[c.size() - 1][1] += t;
            }
            else
            {
                c.push_back({a[i][0] * b[j][0], t});
            }
            if (a[i][1] == 0)
            {
                i++;
            }
            if (b[j][1] == 0)
            {
                j++;
            }
        }
        return c;
    }
};