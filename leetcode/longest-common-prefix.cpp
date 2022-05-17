class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        for (int i = 0;; i++) {
            int j;
            for (j = 0; j < strs.size(); j++) {
                if (i < strs[j].size() && strs[j][i] == strs[0][i]) {
                } else {
                    break;                    
                }
            }
            if (j < strs.size()) {
                return strs[0].substr(0, i);
            }
        }
    }
};