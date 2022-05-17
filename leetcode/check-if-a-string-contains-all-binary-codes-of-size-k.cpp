class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<int> v(1 << k);
        int b = 0;
        for (int i = 0; i < k - 1 && i < s.size(); i++)
        {
            b = (b >> 1) | (s[i] - '0') << (k - 1);
        }
        for (int i = k - 1; i < s.size(); i++)
        {
            b = (b >> 1) | (s[i] - '0') << (k - 1);
            v[b] = 1;
        }
        for (int i: v)
        {
            if (i == 0)
            {
                return false;
            }
        }
        return true;
    }
};