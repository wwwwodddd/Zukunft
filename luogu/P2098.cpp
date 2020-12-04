#include <bits/stdc++.h>
using namespace std;
const int p = 1000000009;
int n, m, l;
pair<int, int> a[2020];
int f[12][12];
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = 0;
	}
	for (int i = n; i < n + m; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = 1;
	}
	sort(a, a + n + m);
	f[0][0] = 1;
	for (int i = 0; i < n + m; i++)
	{
		for (int j = l; j >= 0; j--)
		{
			for (int k = l; k >= j; k--)
			{
				((a[i].second ? f[j][k + 1] : f[j + 1][k]) += f[j][k]) %= p;
			}
		}
	}
	printf("%d\n", f[l][l]);
	return 0;
}