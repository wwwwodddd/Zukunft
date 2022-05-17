class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int c[256] = {};
        int z = 0;
        for (int i = 0, j = 0; i < s.size();)
        {
            k -= !c[s[i++]]++;
            while (k < 0)
            {
                k += !--c[s[j++]];
            }
            z = max(z, i - j);
        }
        return z;
    }
};