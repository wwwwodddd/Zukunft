class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int v, int k) {
        vector<int> z;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = max(i - k, 0); j <= min(i + k, int(a.size()) - 1); j++)
            {
                if (a[j] == v)
                {
                    z.push_back(i);
                    break;
                }
            }
        }
        return z;
    }
};