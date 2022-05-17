class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += vat[i];
        }
        if (s == 0)
        {
            return 0;
        }
        int z = 1e9;
        for (int i = 1; i <= 10000; i++)
        {
            int x = i;
            for (int j = 0; j < n; j++)
            {
                x += max(0, (vat[j] + i - 1) / i - bucket[j]);
            }
            z = min(z, x);
        }
        return z;
    }
};