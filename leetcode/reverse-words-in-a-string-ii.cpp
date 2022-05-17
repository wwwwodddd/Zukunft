class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            if (!isspace(s[i]))
            {
                int j = i;
                while (j < s.size() && !isspace(s[j]))
                {
                    j++;
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
    }
};