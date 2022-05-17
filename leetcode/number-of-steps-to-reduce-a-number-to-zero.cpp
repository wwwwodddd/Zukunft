class Solution {
public:
    int numberOfSteps (int n) {
        if (n == 0)
        {
            return 0;
        }
        return numberOfSteps(n % 2 ? n - 1 : n / 2) + 1;
    }
};