#include <bits/stdc++.h>
using namespace std;
int n, m, l, q;
set<int> r, c;
int o[300020];
int x[300020];
int y[300020];
long long z[300020];
int main()
{
    cin >> n >> m >> l >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> o[i] >> x[i] >> y[i];
    }
    for (int i = q - 1; i >= 0; i--)
    {
        if (o[i] == 1)
        {
            if (r.insert(x[i]).second)
            {
                n -= 1;
                z[y[i]] += m;
            }
        }
        else
        {
            if (c.insert(x[i]).second)
            {
                m -= 1;
                z[y[i]] += n;
            }
        }
    }
    for (int i = 1; i <= l; i++)
    {
        cout << z[i] << " ";
    }
}
