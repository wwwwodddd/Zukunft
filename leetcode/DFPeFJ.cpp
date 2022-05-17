int d[120][120];
vector<pair<int, int> > a[120];
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        for (int i = 0; i <= n; i++)
        {
            a[i].clear();
        }
        for (int i = 0; i < paths.size(); i++)
        {
            a[paths[i][0]].push_back(make_pair(paths[i][1], paths[i][2]));
            a[paths[i][1]].push_back(make_pair(paths[i][0], paths[i][2]));
        }
        memset(d, 0x3f, sizeof d);
        d[start][0] = 0;
        set<pair<int, pair<int, int> > > q;
        q.insert(make_pair(d[start][0], make_pair(start, 0)));
        while (q.size() > 0)
        {
            pair<int, pair<int, int> > u = *q.begin();
            q.erase(q.begin());
            for (int i = 0; i < a[u.second.first].size(); i++)
            {
                pair<int, int> e = a[u.second.first][i];
                if (u.second.second >= e.second)
                {
                    if (d[e.first][u.second.second - e.second] > d[u.second.first][u.second.second] + e.second)
                    {
                        q.erase(make_pair(d[e.first][u.second.second - e.second], make_pair(e.first, u.second.second - e.second)));
                        d[e.first][u.second.second - e.second] = d[u.second.first][u.second.second] + e.second;
                        q.insert(make_pair(d[e.first][u.second.second - e.second], make_pair(e.first, u.second.second - e.second)));
                    }
                }
            }
            if (u.second.second < cnt)
            {
                if (d[u.second.first][u.second.second + 1] > d[u.second.first][u.second.second] + charge[u.second.first])
                {
                    q.erase(make_pair(d[u.second.first][u.second.second + 1], make_pair(u.second.first, u.second.second + 1)));
                    d[u.second.first][u.second.second + 1] = d[u.second.first][u.second.second] + charge[u.second.first];
                    q.insert(make_pair(d[u.second.first][u.second.second + 1], make_pair(u.second.first, u.second.second + 1)));
                }
            }
        }
        return d[end][0];
    }
};