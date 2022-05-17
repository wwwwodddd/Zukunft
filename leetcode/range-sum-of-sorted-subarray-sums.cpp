class Solution {
public:
    int rangeSum(vector<int>& a, int n, int left, int right) {
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            int s = 0;
            for (int j = i; j < n; j++)
            {
                s += a[j];
                b.push_back(s);
            }
        }
        sort(b.begin(), b.end());
        int z = 0;
        for (int i = left-1; i < right; i++)
        {
            z = (z + b[i]) % 1000000007;
        }
        return z;
    }
};