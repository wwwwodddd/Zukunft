class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        a.resize(unique(a.begin(), a.end()) - a.begin());
        return a.size();
    }
};