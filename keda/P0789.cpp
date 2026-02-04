#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[1020];
int y[1020];
bool v[1020];
int d[1020];
int dist(int i, int j)
{
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i < n; i++)
	{
		d[i] = 1e9;
	}
	for (int i = 0; i < n; i++)
	{
		int mind = 1e9;
		int mini = -1;
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
		v[mini] = true;
		for (int j = 0; j < n; j++)
		{
			if (!v[j])
			{
				d[j] = min(d[j], dist(j, mini));
			}
		}
	}
	sort(d, d + n);
	printf("%.2f\n", sqrt(d[n - m + 1]));
	return 0;
}