class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& e, int s, int t) {
        vector<vector<int> > a(n);
        vector<int> d(n);
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][1]].push_back(e[i][0]);
            d[e[i][0]]++;
        }
        queue<int> q;
        if (!d[t])
        {
            q.push(t);
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            if (u == s)
            {
                return true;
            }
            for (int i : a[u])
            {
                if (!--d[i])
                {
                    q.push(i);
                }
            }
        }
        return false;
    }
};