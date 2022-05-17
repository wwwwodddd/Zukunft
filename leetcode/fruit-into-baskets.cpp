class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int, int> g;
        int n = tree.size();
        int j = 0;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && cnt <= 2) {
                ans = max(ans, j - i);
                if (g[tree[j]] == 0) {
                    cnt++;
                }
                g[tree[j]]++;
                j++;
            }
            if (cnt <= 2) {
                ans = max(ans, j - i);
            }
            g[tree[i]]--;
            if (g[tree[i]] == 0) {
                cnt--;
            }
        }
        return ans;
    }
};