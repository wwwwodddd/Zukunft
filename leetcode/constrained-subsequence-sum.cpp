class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        deque<int> q;
        vector<int> f;
        int n = a.size(), z = a[0];
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            while (q.size() && q.front() < i - k)
            {
                q.pop_front();
            }
            if (q.size())
            {
                f[i] = f[q.front()];
            }
            f[i] += a[i];
            z = max(z, f[i]);
            if (f[i] > 0)
            {
                while (q.size() && f[q.back()] < f[i])
                {
                    q.pop_back();
                }
                q.push_back(i);
            }
        }
        return z;
    }
};