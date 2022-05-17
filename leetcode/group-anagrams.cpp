class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > g;
        for (string s: strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            g[t].push_back(s);
        }
        vector<vector<string>> re;
        for (auto &i: g)
        {
            re.push_back(i.second);
        }
        return re;
    }
};