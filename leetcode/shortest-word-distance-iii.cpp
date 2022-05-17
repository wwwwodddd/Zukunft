class Solution {
public:
    int shortestWordDistance(vector<string>& w, string x, string y) {
        map<string, vector<int> > g;
        int n = w.size();
        for (int i = 0; i < n; i++)
        {
            g[w[i]].push_back(i);
        }
        vector<int> &a = g[x];
        vector<int> &b = g[y];
        int z = n;
        if (x != y)
        {
            int i = 0, j = 0;
            while (i < a.size() && j < b.size())
            {
                z = min(z, abs(a[i] - b[j]));
                if (a[i] < b[j])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }
        else
        {
            for (int i = 1; i < a.size(); i++)
            {
                z = min(z, a[i] - a[i - 1]);
            }
        }
        return z;
    }
};