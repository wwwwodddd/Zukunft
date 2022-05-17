class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& a, int m) {
        multiset<pair<double, pair<int, int> > > s;
        for (int i = 0; i < a.size(); i++)
        {
            s.insert(make_pair(double(a[i][0]) / a[i][1] - double(a[i][0] + 1) / (a[i][1] + 1), make_pair(a[i][0], a[i][1])));
        }
        for (int i = 0; i < m; i++)
        {
            pair<double, pair<int, int> > u = *s.begin();
            s.erase(s.begin());
            u.second.first++;
            u.second.second++;
            u.first = (u.second.first + 0.0) / (u.second.second + 0.0) - (u.second.first + 1.0) / (u.second.second + 1.0);
            s.insert(u);
        }
        double t = 0;
        for (auto i : s)
        {
            t += double(i.second.first) / i.second.second;
        }
        return t / s.size();
    }
};