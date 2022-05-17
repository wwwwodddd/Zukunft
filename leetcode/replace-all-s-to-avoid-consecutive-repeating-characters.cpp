class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                s[i] = 'a';
            }
            while (i > 0 && s[i] == s[i - 1] || i + 1 < s.size() && s[i] == s[i + 1])
            {
                s[i]++;
            }
        }
        return s;
    }
};