class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& a, int l) {
        int n = a.size();
        sort(a.begin(), a.end());
        int z = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            a[i][1]++;
        }
        for (int i = 0, j = 0; i < n;)
        {
            while (j < n && a[j][1] <= a[i][0] + l)
            {
                s += a[j][1] - a[j][0];
                j++;
            }
            int t = 0;
            if (j < n)
            {
                t = max(a[i][0] + l - a[j][0], 0);
            }
            z = max(z, s + t);
            s -= a[i][1] - a[i][0];
            i++;
        }
        return z;
    }
};