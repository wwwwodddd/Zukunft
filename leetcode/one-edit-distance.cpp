class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int is = 0, js = s.size();
        int it = 0, jt = t.size();
        while (is < js && it < jt && s[is] == t[it])
        {
            is++;
            it++;
        }
        while (is < js && it < jt && s[js - 1] == t[jt - 1])
        {
            js--;
            jt--;
        }
        if (is == js && it + 1 == jt)
        {
            return true;
        }
        if (is + 1 == js && it == jt)
        {
            return true;
        }
        if (is + 1 == js && it + 1 == jt)
        {
            return true;
        }
        return false;
    }
};