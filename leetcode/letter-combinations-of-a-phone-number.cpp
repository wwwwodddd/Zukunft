class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret, tmp;
        if (digits == "") {
            return ret;
        }
        ret.push_back("");
        string button[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char c: digits) {
            tmp.clear();
            for (char d: button[c - '0']) {
                for (string s: ret) {
                    tmp.push_back(s + d);
                }
            }
            ret.swap(tmp);
        }
        return ret;
    }
};