class Solution {
public:
    int countLatticePoints(vector<vector<int>>& a) {
        int mnx = 100, mny = 100;
        int mxx = 1, mxy = 1;
        int mxr = 1;
        for (int i = 0; i < a.size(); i++)
        {
            mnx = min(mnx, a[i][0]);
            mxx = max(mxx, a[i][0]);
            mny = min(mny, a[i][1]);
            mxy = max(mxy, a[i][1]);
            mxr = max(mxr, a[i][2]);
        }
        int z = 0;
        for (int i = mnx - mxr; i <= mxx + mxr; i++)
        {
            for (int j = mny - mxr; j <= mxy + mxr; j++)
            {
                for (int k = 0; k < a.size(); k++)
                {
                    int dx = i - a[k][0];
                    int dy = j - a[k][1];
                    if (dx * dx + dy * dy <= a[k][2] * a[k][2])
                    {
                        z++;
                        break;
                    }
                }
            }
        }
        return z;
    }
};