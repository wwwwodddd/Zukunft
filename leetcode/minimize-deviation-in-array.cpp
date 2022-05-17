class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        set<int> s;
        for (int i: a)
        {
            if (i & 1)
            {
                s.insert(i * 2);
            }
            else
            {
                s.insert(i);                
            }
        }
        int z = 1e9;
        while (true)
        {
            z = min(z, *--s.end() - *s.begin());
            int r = *--s.end();
            s.erase(--s.end());
            if (r & 1)
            {
                break;
            }
            else
            {
                s.insert(r / 2);
            }
        }
        return z;
    }
};