class Solution {
public:
    long long buildBridge(int m, vector<vector<int>>& a) {
        int n = a.size();
        multiset<long long> L, R;
        L.insert(0);
        R.insert(m + 1);
        long long ld = 0;
        long long rd = 0;
        long long z = 0;
        for (int i = 0; i < a.size(); i++)
        {
            // cout << "i=" << i << endl;
            if (a[i][1] <= *L.rbegin() + ld)
            {
                z += (*L.rbegin() + ld) - (a[i][1] - 1);
                // cout << "L ADD " << z << " " << (a[i][1] - 1) << " " << (*L.rbegin() + ld) << endl;
                rd += a[i][1] - a[i][0];
                R.insert(*L.rbegin() + 2 + ld - rd);
                L.erase(--L.end());
                ld -= a[i][1] - a[i][0];
                L.insert(a[i][0] - 1 - ld);
                L.insert(a[i][0] - 1 - ld);
            }
            else if (a[i][0] >= *R.begin() + rd)
            {
                z += (a[i][0] + 1) - (*R.begin() + rd);
                // cout << "R ADD " << z << " " << (a[i][0] + 1) << " " << (*R.begin() + rd) << endl;
                ld -= a[i][1] - a[i][0];
                L.insert(*R.begin() - 2 + rd - ld);
                R.erase(R.begin());
                rd += a[i][1] - a[i][0];
                R.insert(a[i][1] + 1 - rd);
                R.insert(a[i][1] + 1 - rd);
            }
            else
            {
                // cout << "INTER" << endl;
                ld -= a[i][1] - a[i][0];
                rd += a[i][1] - a[i][0];
                L.insert(a[i][0] - 1 - ld);
                R.insert(a[i][1] + 1 - rd);
            }
            // assert(*L.rbegin() + ld < *R.begin() + rd - 1);
            // cout << "L=";
            // for (int i: L)
            // {
            //     cout << i + ld << " ";
            // }
            // cout << endl;
            // cout << "R=";
            // for (int i: R)
            // {
            //     cout << i + rd << " ";
            // }
            // cout << endl;
        }
        return z;
    }
};