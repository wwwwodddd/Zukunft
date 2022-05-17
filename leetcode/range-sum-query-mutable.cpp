class NumArray {
public:
    vector<int> b;
    vector<int> c;
    int n;
    NumArray(vector<int>& a) {
        b = a;
        n = a.size();
        c.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            c[i + 1] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (i + (i & -i) <= n)
            {
                c[i + (i & -i)] += c[i];
            }
        }
    }
    void change(int x, int y)
    {
        for (; x <= n; x += x & -x)
        {
            c[x] += y;
        }
    }
    void update(int x, int y) {
        change(x + 1, y - b[x]);
        b[x] = y;
    }
    int query(int x)
    {
        int re = 0;
        for (; x > 0; x -= x & -x)
        {
            re += c[x];
        }
        return re;
    }
    int sumRange(int l, int r) {
        return query(r + 1) - query(l);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */