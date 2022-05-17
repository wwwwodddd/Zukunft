class Solution {
public:
    int countHillValley(vector<int>& a) {
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int z = 0;
        for (int i = 1; i + 1 < a.size(); i++)
        {
            z += (a[i - 1] < a[i]) ^ (a[i] < a[i + 1]);
        }
        return z;
    }
};