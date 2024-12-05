#include <bits/stdc++.h>
using namespace std;
pair<double, int> a[120];
int n, m;
double z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%lf", &a[i].second, &a[i].first);
		a[i].first /= a[i].second;
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		int u = min(m, a[i].second);
		m -= u;
		z += u * a[i].first;
	}
	printf("%.2f\n", z);
	return 0;
}