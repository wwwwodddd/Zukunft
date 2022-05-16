#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, l;
int a[300020];
int s[300020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &l);
		for (int i = 0, j = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			while (a[j] <= a[i] - l)
			{
				j++;
			}
			s[i + 1] = (s[i] + s[j] + 1) % p;
		}
		printf("%d\n", s[n]);
	}
	return 0;
}