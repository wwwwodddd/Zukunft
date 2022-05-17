class Solution {
public:
    int ladderLength(string s, string t, vector<string>& a) {
        map<string, int> g;
        for (string i: a)
        {
            g[i] = 0;
        }
        queue<string> q;
        g[s] = 1;
        q.push(s);
        while (q.size())
        {
            string u = q.front();
            int d = g[u];
            q.pop();
            for (int i = 0; i < u.size(); i++)
            {
                char c = u[i];
                for (int j = 'a'; j <= 'z'; j++)
                {
                    u[i] = j;
                    if (g.find(u) != g.end() && g[u] == 0)
                    {
                        g[u] = d + 1;
                        q.push(u);
                    }
                }
                u[i] = c;
            }
        }
        return g[t];
    }
};