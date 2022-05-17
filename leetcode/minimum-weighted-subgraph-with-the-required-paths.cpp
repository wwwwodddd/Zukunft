class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& e, int src1, int src2, int dest) {
        vector<pair<int, int> > a[n];
        vector<pair<int, int> > b[n];
        priority_queue<pair<int, int> > q;
        vector<long long> d0(n);
        vector<long long> d1(n);
        vector<long long> d2(n);
        for (int i = 0; i < e.size(); i++) {
            a[e[i][0]].push_back(make_pair(e[i][1], e[i][2]));
            b[e[i][1]].push_back(make_pair(e[i][0], e[i][2]));
        }
        fill(d0.begin(), d0.end(), 1e18);
        fill(d1.begin(), d1.end(), 1e18);
        fill(d2.begin(), d2.end(), 1e18);
    	d0[dest] = 0;
        q.push(make_pair(-d0[dest], dest));
        while (q.size() > 0) {
            pair<int, int> u = q.top();
            q.pop();
            if (-u.first > d0[u.second]) {
                continue;
            }
            for (int i = 0; i < b[u.second].size(); i++) {
                pair<int, int> e = b[u.second][i];
                if (d0[e.first] > d0[u.second] + e.second) {
                    d0[e.first] = d0[u.second] + e.second;
                    q.push(make_pair(-d0[e.first], e.first));
                }
            }
        }
        d1[src1] = 0;
        q.push(make_pair(-d1[src1], src1));
        while (q.size() > 0) {
            pair<int, int> u = q.top();
            q.pop();
            if (-u.first > d1[u.second]) {
                continue;
            }
            for (int i = 0; i < a[u.second].size(); i++) {
                pair<int, int> e = a[u.second][i];
                if (d1[e.first] > d1[u.second] + e.second) {
                    d1[e.first] = d1[u.second] + e.second;
                    q.push(make_pair(-d1[e.first], e.first));
                }
            }
        }
        d2[src2] = 0;
        q.push(make_pair(-d2[src2], src2));
        while (q.size() > 0) {
            pair<int, int> u = q.top();
            q.pop();
            if (-u.first > d2[u.second]) {
                continue;
            }
            for (int i = 0; i < a[u.second].size(); i++) {
                pair<int, int> e = a[u.second][i];
                if (d2[e.first] > d2[u.second] + e.second) {
                    d2[e.first] = d2[u.second] + e.second;
                    q.push(make_pair(-d2[e.first], e.first));
                }
            }
        }
        long long ans = 1e18;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, d0[i] + d1[i] + d2[i]);
        }
        if (ans == 1e18)
        {
            ans = -1;
        }
        return ans;
    }
};