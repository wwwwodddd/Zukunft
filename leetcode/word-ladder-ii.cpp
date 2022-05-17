class Solution {
public:
    vector<vector<string>> findLadders(string s, string t, vector<string>& a) {
        map<string, int> g;
        map<string, vector<vector<string> > > p;
        for (string i: a)
        {
            g[i] = 0;
        }
        queue<string> q;
        g[s] = 1;
        p[s].push_back({s});
        q.push(s);
        while (q.size())
        {
            string u = q.front();
            int d = g[u];
            vector<vector<string> > &e = p[u];
            q.pop();
            for (int i = 0; i < u.size(); i++)
            {
                char c = u[i];
                for (int j = 'a'; j <= 'z'; j++)
                {
                    u[i] = j;
                    auto it = g.find(u);
                    if (it != g.end() && it->second == 0)
                    {
                        it->second = d + 1;
                        for (auto f : e)
                        {
                            f.push_back(u);
                            p[u].push_back(f);
                        }
                        q.push(u);
                    }
                    else if (it != g.end() && it->second == d + 1)
                    {
                        for (auto f : e)
                        {
                            f.push_back(u);
                            p[u].push_back(f);
                        }
                    }
                }
                u[i] = c;
            }
        }
        return p[t];
    }
};