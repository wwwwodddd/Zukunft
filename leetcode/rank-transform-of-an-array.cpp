class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (int i = 0; i < a.size(); i++)
        {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        }
        return a;
    }
};