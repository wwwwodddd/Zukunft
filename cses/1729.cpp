#include <bits/stdc++.h>
using namespace std;
int n, k, a[100];
int f[1000020];
int main()
{
	scanf("%d%d", &n, &k);
	for (int j = 0; j < k; j++)
	{
		scanf("%d", &a[j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i >= a[j] && f[i - a[j]] == 0)
			{
				f[i] = 1;
				break;
			}
		}
		printf(f[i] ? "W" : "L");
	}
	puts("");
	return 0;
}