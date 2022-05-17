class Solution {
public:
    long long appealSum(string s) {
        map<int, int> g;
        int n = s.size();
        long long z = 0;
        for (int i = 0; i < s.size(); i++)
        {
            g[s[i]] = i + 1;
            for (auto j : g)
            {
                z += j.second;
            }
        }
        return z;
    }
};