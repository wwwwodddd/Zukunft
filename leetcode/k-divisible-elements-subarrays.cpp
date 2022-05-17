class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        set<vector<int> > s;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> u;
            int c = 0;
            for (int j = i; j < n; j++)
            {
                if (a[j] % p == 0)
                {
                    c++;
                }
                if (c > k)
                {
                    break;
                }
                u.push_back(a[j]);
                s.insert(u);
            }
        }
        return s.size();
    }
};