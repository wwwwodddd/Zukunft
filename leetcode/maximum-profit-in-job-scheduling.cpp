class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<int> l;
        for (int i: s)
        {
            l.push_back(i);
        }
        for (int i: e)
        {
            l.push_back(i);
        }
        sort(l.begin(), l.end());
        l.resize(unique(l.begin(), l.end()) - l.begin());
        for (int&i: s)
        {
            i = lower_bound(l.begin(), l.end(), i) - l.begin();
        }
        for (int&i: e)
        {
            i = lower_bound(l.begin(), l.end(), i) - l.begin();
        }
        vector<pair<pair<int, int>, int> > a;
        for (int i = 0; i < p.size(); i++)
        {
            a.push_back({{e[i], s[i]}, p[i]});
        }
        for (int i = 1; i < l.size(); i++)
        {
            a.push_back({{i, i-1}, 0});
        }
        sort(a.begin(), a.end());
        vector<int> f(l.size());
        for (auto i: a)
        {
            f[i.first.first] = max(f[i.first.first], f[i.first.second] + i.second);
        }
        return f.back();
    }
};