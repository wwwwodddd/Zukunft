class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double> > > a(n);
        vector<double> d(n);
        for (int i = 0; i < succProb.size(); i++)
        {
            a[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            a[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        set<pair<double, int> > s;
        d[start] = 1;
        s.insert(make_pair(-d[start], start));
        while (s.size() > 0)
        {
            int u = s.begin()->second;
            s.erase(s.begin());
            for (pair<int, double> i: a[u])
            {
                if (d[i.first] < d[u] * i.second)
                {
                    s.erase(make_pair(-d[i.first], i.first));
                    d[i.first] = d[u] * i.second;
                    s.insert(make_pair(-d[i.first], i.first));
                }
            }
        }
        return d[end];
    }
};