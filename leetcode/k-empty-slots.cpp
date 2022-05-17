class Solution {
public:
    int kEmptySlots(vector<int>& a, int k) {
        set<int> s;
        int z = -1;
        for (int i = 0; i < a.size(); i++)
        {
            auto it = s.lower_bound(a[i]);
            if (it != s.end())
            {
                if (*it - a[i] == k + 1)
                {
                    z = i + 1;
                    break;
                }
            }
            if (it != s.begin())
            {
                it--;
                if (a[i] - *it == k + 1)
                {
                    z = i + 1;
                    break;
                }
            }
            s.insert(a[i]);
        }
        return z;
    }
};