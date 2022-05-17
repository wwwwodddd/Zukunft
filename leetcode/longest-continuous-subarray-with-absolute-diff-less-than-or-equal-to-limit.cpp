class Solution {
public:
    int longestSubarray(vector<int>& a, int l) {
        multiset<int> s;
        int z = 0;
        for (int i = 0, j = 0; i < a.size();)
        {
            s.insert(a[i++]);
            while (*s.rbegin() - *s.begin() > l)
            {
                s.erase(s.find(a[j++]));
            }
            z = max(z, i - j);
        }
        return z;
    }
};