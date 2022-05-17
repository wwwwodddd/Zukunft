class Solution {
public:
    bool isValid(string s) {
        vector<char> t;
        for (char c: s)
        {
            if (c == ')')
            {
                if (t.size() > 0 && t.back() == '(')
                {
                    t.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (c == ']')
            {
                if (t.size() > 0 && t.back() == '[')
                {
                    t.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (c == '}')
            {
                if (t.size() > 0 && t.back() == '{')
                {
                    t.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                t.push_back(c);
            }
        }
        return t.size() == 0;
    }
};