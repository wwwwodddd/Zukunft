#include <bits/stdc++.h>
using namespace std;
int n, x, y, d[]={0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
double f[999], r;
vector<pair<int, double> > a[999];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%lf", &x, &y, &r);
		a[d[x / 100] + x % 100].push_back(make_pair(y, 1 + r * y / 36500));
	}
	f[0] = 1e5;
	for (int i = 0; i < 366; i++)
	{
		f[i + 1] = max(f[i + 1], f[i]);
		for (pair<int, double> j: a[i])
		{
			f[i + j.first] = max(f[i + j.first], f[i] * j.second);
		}
	}
	printf("%.2f\n", f[366]);
	return 0;
}