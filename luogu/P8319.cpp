#include <bits/stdc++.h>
using namespace std;
int t, n = 2000010;
int v[2000020];
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}			
		}
	}
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] != i)
		{
			v[i] = v[i - 1];
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", v[n]);
	}
	return 0;
}
