#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, m, k;
int main()
{
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> n >> m >> k;
		ll L = 0, R = 2e9;
		while (L < R - 1)
		{
			ll M = (L + R) / 2;
			if ((n / M) * (m / M) < k)
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		if (L == 0)
		{
			L--;
		}
		cout << "Case " << tt << ": " << L << endl;
	}
	return 0;
}