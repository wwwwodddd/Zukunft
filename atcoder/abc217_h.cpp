#include <bits/stdc++.h>
using namespace std;
multiset<long long> L, R;
int n;
long long z, t, d, x;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> d >> x;
		if (L.size() == 0)
		{
			L.insert(0);
		}
		if (R.size() == 0)
		{
			R.insert(0);
		}
		if (d == 0)
		{
			if (x >= t - *R.rbegin())
			{
				z += x - (t - *R.rbegin());
				L.insert(2 * t - *R.rbegin());
				R.erase(--R.end());
				if (x <= t)
				{
					R.insert(t - x);
				}
			}
			else if (x >= -t)
			{
				L.insert(t + x);
			}
		}
		else
		{
			if (x <= *L.rbegin() - t)
			{
				z += (*L.rbegin() - t) - x;
				R.insert(2 * t - *L.rbegin());
				L.erase(--L.end());
				if (x >= -t)
				{
					L.insert(x + t);
				}
			}
			else if (x <= t)
			{
				R.insert(t - x);
			}
		}
	}
	cout << z << endl;
	return 0;
}