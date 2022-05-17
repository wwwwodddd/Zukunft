class Solution {
public:
    vector<int> lm, rm, mx;
    vector<char> lc, rc, mc;
    string ss;
    void update(int x, int l, int r, int m)
    {
        if (m - l == lm[x * 2 + 1] && lc[x * 2 + 1] == lc[x * 2 + 2])
        {
            lm[x] = m - l + lm[x * 2 + 2];
            lc[x] = lc[x * 2 + 2];
        }
        else
        {
            lm[x] = lm[x * 2 + 1];
            lc[x] = lc[x * 2 + 1];
        }
        if (r - m == rm[x * 2 + 2] && rc[x * 2 + 1] == rc[x * 2 + 2])
        {
            rm[x] = r - m + rm[x * 2 + 1];
            rc[x] = rc[x * 2 + 1];
        }
        else
        {
            rm[x] = rm[x * 2 + 2];
            rc[x] = rc[x * 2 + 2];
        }
        int mxx = max(mx[x * 2 + 1], mx[x * 2 + 2]);
        if (rc[x * 2 + 1] == lc[x * 2 + 2])
        {
            mxx = max(mxx, rm[x * 2 + 1] + lm[x * 2 + 2]);
        }
        if (mxx == mx[x * 2 + 1])
        {
            mx[x] = mx[x * 2 + 1];
            mc[x] = mc[x * 2 + 1];
        }
        else if (mxx == mx[x * 2 + 2])
        {
            mx[x] = mx[x * 2 + 2];
            mc[x] = mc[x * 2 + 2];
        }
        else
        {
            mx[x] = rm[x * 2 + 1] + lm[x * 2 + 2];
            mc[x] = rc[x * 2 + 1];
        }
    }
    void build(int x, int l, int r)
    {
        if (l + 1 == r)
        {
            lc[x] = rc[x] = mc[x] = ss[l];
            lm[x] = rm[x] = mx[x] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(x * 2 + 1, l, m);
        build(x * 2 + 2, m, r);
        update(x, l, r, m);
    }
    void change(int x, int l, int r, int p, char c)
    {
        if (l + 1 == r)
        {
            lc[x] = rc[x] = mc[x] = c;
            lm[x] = rm[x] = mx[x] = 1;
            return;
        }
        int m = (l + r) / 2;
        if (p < m)
        {
            change(x * 2 + 1, l, m, p, c);
        }
        else
        {
            change(x * 2 + 2, m, r, p, c);
        }
        update(x, l, r, m);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        ss = s;
        int m = s.size();
        lm.resize(m * 4 + 100);
        rm.resize(m * 4 + 100);
        mx.resize(m * 4 + 100);
        lc.resize(m * 4 + 100);
        rc.resize(m * 4 + 100);
        mc.resize(m * 4 + 100);
        build(0, 0, m);
        vector<int> ans;
        for (int i = 0; i < queryCharacters.size(); i++)
        {
            change(0, 0, m, queryIndices[i], queryCharacters[i]);
            ans.push_back(mx[0]);
        }
        return ans;
    }
};