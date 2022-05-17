class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> p[26];
        vector<int> a(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            p[s[i] - 'a'].push_back(i);
        }
        int c[26] = {};
        for (int i = 0; i < t.size(); i++)
        {
            a[i] = p[t[i] - 'a'][c[t[i] - 'a']++];
        }
        int z = 0;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] > a[i])
                {
                    z++;
                }
            }
        }
        return z / 2;
    }
};