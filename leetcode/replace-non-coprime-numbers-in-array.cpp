class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> s;
        for (int i = 0; i < a.size(); i++)
        {
            int x = a[i];
            while (s.size() > 0 && __gcd(x, s[s.size() - 1]) > 1)
            {
                x = x / __gcd(x, s[s.size() - 1]) * s[s.size() - 1];
                s.pop_back();
            }
            s.push_back(x);
        }
        return s;
    }
};