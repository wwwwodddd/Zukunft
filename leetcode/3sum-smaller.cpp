class Solution {
public:
    int threeSumSmaller(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        int n = a.size();
        int z = 0;
        for (int k = n - 1; k >= 0; k--)
        {
            for (int i = 0, j = k - 1; j >= 0; j--)
            {
                while (i < j && a[i] + a[j] + a[k] < t)
                {
                    i++;
                }
                z += min(i, j);
            }
        }
        return z;
    }
};