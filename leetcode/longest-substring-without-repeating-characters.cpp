class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> g;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j < s.size() && g[s[j]] == 0) {
                g[s[j]]++;
                j++;
            }
            ans = max(ans, j - i);
            g[s[i]]--;
        }
        return ans;
    }
};