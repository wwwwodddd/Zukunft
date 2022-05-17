class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        priority_queue<int> q;
        for (int i: a)
        {
            q.push(i);
        }
        for (int i = 0; i < k; i++)
        {
            int x = (q.top() + 1) / 2;
            q.pop();
            q.push(x);
        }
        int z = 0;
        while (q.size())
        {
            z += q.top();
            q.pop();
        }
        return z;
    }
};