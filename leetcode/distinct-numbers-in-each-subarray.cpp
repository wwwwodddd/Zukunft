class Solution {
public:
    vector<int> distinctNumbers(vector<int>& a, int k) {
        vector<int> c(100001), z;
        int d = 0;
        for (int i = 0; i < a.size();)
        {
            d += !c[a[i++]]++;
            if (i >= k)
            {
                z.push_back(d);
                d -= !--c[a[i - k]];
            }
        }
        return z;
    }
};