class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> f(cost.size() + 1);
        for (int i = 2; i <= cost.size(); i++)
        {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }
        return f[cost.size()];
    }
};