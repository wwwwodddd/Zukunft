#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int l = 0, r = n - 1, z = 0;
		while (l < r)
		{
			while (l < r && a[l] != 1)
			{
				l++;
			}
			while (l < r && a[r] != 0)
			{
				r--;
			}
			if (l < r)
			{
				l++;
				r--;
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}