class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<pair<int, int> > a;
        for (auto i: f)
        {
            a.push_back(make_pair(i[0], 1));
            a.push_back(make_pair(i[1]+1, -1));
        }
        for (int i = 0; i < p.size(); i++)
        {
            a.push_back(make_pair(p[i], i + 100));
        }
        sort(a.begin(), a.end());
        vector<int> z;
        z.resize(p.size());
        int s = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].second >= 100)
            {
                z[a[i].second - 100] = s;
            }
            else
            {
                s += a[i].second;
            }
        }
        return z;
    }
};