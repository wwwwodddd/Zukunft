#include <bits/stdc++.h>
using namespace std;
int s[100020];
int a[100020];
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int ss = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0, j = 0; j < n; j++)
		{
			scanf("%d", &x);
			while (i < n && s[ss] != x)
			{
				s[++ss] = a[i++];
			}
			if (s[ss] == x)
			{
				--ss;
			}
		}
		puts(ss > 0 ? "No" : "Yes");
	}
	return 0;
}