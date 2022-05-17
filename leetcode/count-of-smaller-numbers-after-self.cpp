class Solution {
public:
    vector<int> c;
    void change(int x, int y)
    {
        x += 10010;
        for (; x < 20010; x += x & -x)
        {
            c[x] += y;
        }
    }
    int query(int x)
    {
        x += 10010;
        int re = 0;
        for (; x > 0; x -= x & -x)
        {
            re += c[x];
        }
        return re;
    }
    vector<int> countSmaller(vector<int>& nums) {
        c.resize(20020);
        vector<int> re(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            re[i] = query(nums[i] - 1);
            change(nums[i], 1);
        }
        return re;
    }
};