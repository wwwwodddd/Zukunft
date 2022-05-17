class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& r) {
        vector<pair<pair<int, int>, int> > a;
        for (int i = 0; i < r.size(); i++)
        {
            a.push_back({{r[i][1], r[i][0]}, r[i][1] - r[i][0] + r[i][2]});
        }
        for (int i = 1; i <= n; i++)
        {
            a.push_back({{i, i-1}, 0});
        }
        sort(a.begin(), a.end());
        vector<long long> f(n + 1);
        for (auto i: a)
        {
            f[i.first.first] = max(f[i.first.first], f[i.first.second] + i.second);
        }
        return f.back();
    }
};