class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        map<int, int> g;
        int z = 0;
        for (int i: a)
        {
            z += g[i]++;
        }
        return z;
    }
};