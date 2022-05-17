class Solution {
public:
    int minimumBuckets(string s) {
        int z = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'H')
            {
                if (i > 0 && s[i - 1] == 'B')
                {
                }
                else if (i + 1 < s.size() && s[i + 1] == '.')
                {
                    s[i + 1] = 'B';
                    z++;
                }
                else if (i > 0 && s[i - 1] == '.')
                {
                    s[i - 1] = 'B';
                    z++;
                }
                else
                {
                    return -1;
                }
            }
        }
        return z;
    }
};