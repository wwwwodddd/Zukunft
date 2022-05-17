class Solution {
public:
    int largestVariance(string s) {
        int z = 0;
        for (char j = 'a'; j <= 'z'; j++)
        {
            for (char k = 'a'; k <= 'z'; k++)
            {
                if (j == k)
                {
                    continue;
                }
                int x = 0, y = -1e9;
                for (int i = 0; i < s.size(); i++)
                {
                    if (s[i] == j)
                    {
                        x += 1;
                        y += 1;
                        z = max(z, y);
                    }
                    else if (s[i] == k)
                    {
                        y = max(y - 1, x - 1);
                        x = max(x - 1, 0);
                        z = max(z, y);
                    }
                }
            }
        }
        return z;
    }
};