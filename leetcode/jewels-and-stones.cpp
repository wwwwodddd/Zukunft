class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt = 0;
        for (char i: J) {
            for (char j: S) {
                if (i == j) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};