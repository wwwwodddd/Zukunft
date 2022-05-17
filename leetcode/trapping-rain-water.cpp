class Solution {
public:
    int trap(vector<int>& a) {
        vector<int> pre(a.size());
        vector<int> suf(a.size());
        pre[0] = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            pre[i] = max(pre[i - 1], a[i]);
        }
        suf[a.size() - 1] = a[a.size() - 1];
        for (int i = a.size() - 2; i >= 0; i--)
        {
            suf[i] = max(suf[i + 1], a[i]);
        }
        int  z = 0;
        for (int i = 0; i < a.size(); i++)
        {
            z += min(pre[i], suf[i]) - a[i];
        }
        return z;
    }
};