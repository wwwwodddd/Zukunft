class Solution {
public:
    long long sumScores(string s) {
          int n = (int)s.length();
          vector<int> z(n);
          for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r && z[i - l] < r - i + 1) {
              z[i] = z[i - l];
            } else {
              z[i] = max(0, r - i + 1);
              while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            }
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
          }
        long long fuck = s.size();
        for (int i:z)
        {
            fuck += i;
        }
        return fuck;
    }
};