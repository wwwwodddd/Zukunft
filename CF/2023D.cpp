#include <bits/stdc++.h>
using namespace std;
const int m = 200000;
int n, p, w;
vector<int> a[101];
double f[m + 20];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &p, &w);
		a[p].push_back(w);
	}
	f[0] = 1;
	for (int i = 1; i < 100; i++)
	{
		sort(a[i].begin(), a[i].end(), greater<int>());
		for (int j = 0; j < a[i].size() && j * (100 - i) < 100; j++)
		{
			for (int k = m; k >= a[i][j]; k--)
			{
				f[k] = max(f[k], f[k - a[i][j]] * i * 0.01);
			}
		}
	}
	long long s = 0;
	double z = 0;
	for (int i : a[100])
	{
		s += i;
	}
	for (int i = 0; i <= m; i++)
	{
		z = max(z, (s + i) * f[i]);
	}
	printf("%.9f\n", z);
	return 0;
}