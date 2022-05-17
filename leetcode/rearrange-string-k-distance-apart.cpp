class Solution {
public:
    string rearrangeString(string s, int k) {
        map<char, int> g;
        for (char i : s)
        {
            g[i] += 1;
        }
        priority_queue<pair<int, char> > a;
        queue<pair<int, char> > q;
        for (auto i : g)
        {
            a.push(make_pair(i.second, i.first));
        }
        string z;
        for (int i = 0; i < s.size(); i++)
        {
            if (a.size() == 0)
            {
                return "";
            }
            auto u = a.top();
            a.pop();
            z += u.second;
            u.first--;
            q.push(u);
            if (q.size() >= k)
            {
                auto v = q.front();
                q.pop();
                if (v.first)
                {
                    a.push(v);
                }
            }
        }
        return z;
    }
};