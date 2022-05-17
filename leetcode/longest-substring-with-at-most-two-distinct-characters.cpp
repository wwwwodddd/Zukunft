class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> c(256);
        int d = 0, z = 0;
        for (int i = 0, j = 0; i < s.size();)
        {
            d += !c[s[i++]]++;
            while (d > 2)
            {
                d -= !--c[s[j++]];
            }
            z = max(z, i - j);
        }
        return z;
    }
};