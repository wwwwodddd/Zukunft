class Solution {
public:
    int shareCandies(vector<int>& a, int k) {
        vector<int> c(100001);
        int z = 0, s = 0;
        for (int i = k; i < a.size(); i++)
        {
            s += !c[a[i]]++;
        }
        z = s;
        for (int i = k; i < a.size(); i++)
        {
            s += !c[a[i - k]]++;
            s -= !--c[a[i]];
            z = max(z, s);
        }
        return z;
    }
};