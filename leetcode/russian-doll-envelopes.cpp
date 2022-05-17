class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& b) {
        vector<pair<int, int> > a;
        for (int i = 0; i < b.size(); i++)
        {
            a.push_back(make_pair(b[i][0], -b[i][1]));
        }
        sort(a.begin(), a.end());
        vector<int> f(b.size());
        fill(f.begin(), f.end(), 0x3f3f3f3f);
        for (int i = 0; i < a.size(); i++)
        {
            *lower_bound(f.begin(), f.end(), -a[i].second) = -a[i].second;
        }
        return lower_bound(f.begin(), f.end(), 0x3f3f3f3f) - f.begin();
    }
};