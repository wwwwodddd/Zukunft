#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10020];
int f[10020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int mx = 0;
		for (int j = i - 1; j >= i - m && j >= 0; j--) // last group [j, i-1] length i-j
		{
			mx = max(mx, a[j]);
			f[i] = max(f[i], f[j] + (i-j) * mx);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}