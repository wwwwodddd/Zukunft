class Solution {
public:
    int minBuildTime(vector<int>& a, int d) {
        multiset<int> s;
        for (int i: a)
        {
            s.insert(i);
        }
        for (int i = 1; i < a.size(); i++)
        {
            int x = *s.begin();
            s.erase(s.begin());
            int y = *s.begin();
            s.erase(s.begin());
            s.insert(max(x, y) + d);
        }
        return *s.begin();
    }
};