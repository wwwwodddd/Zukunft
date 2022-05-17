class Solution {
public:
    int largestCombination(vector<int>& a) {
        int z = 0;
        for (int i = 0; i < 30; i++)
        {
            int c = 0;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] >> i & 1)
                {
                    z = max(z, ++c);
                }
            }
        }
        return z;
    }
};