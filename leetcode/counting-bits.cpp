class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> a(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            a[i] = a[i / 2] + i % 2;
        }
        return a;
    }
};