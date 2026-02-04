#include <bits/stdc++.h>
using namespace std;
int t, n;
int x[2020];
int y[2020];
int d[2020];
bool v[2020];
int ans;
int dist(int i, int j)
{
	if (x[i] == x[j])
	{
		return (abs(y[i] - y[j]) + 1) / 2;
	}
	if (y[i] == y[j])
	{
		return (abs(x[i] - x[j]) + 1) / 2;
	}
	return max(abs(y[i] - y[j]), abs(x[i] - x[j]));
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
		ans = 0;
		memset(v, 0, sizeof v);
		for (int i = 1; i < n; i++)
		{
			d[i] = 1e9;
		}
		for (int i = 0; i < n; i++)
		{
			int mini = -1;
			int mind = 1e9;
			for (int j = 0; j < n; j++)
			{
				if (!v[j])
				{
					if (mind > d[j])
					{
						mind = d[j];
						mini = j;
					}
				}
			}
			ans = max(ans, mind);
			v[mini] = true;
			for (int j = 0; j < n; j++)
			{
				if (!v[j])
				{
					d[j] = min(d[j], dist(j, mini));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}