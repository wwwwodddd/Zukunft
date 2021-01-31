#include <bits/stdc++.h>
using namespace std;
int t, n, s, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		s = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			s += x;
		}
		printf("%d\n", s);
		for (int i = 0; i < n; i++)
		{
			printf("1%c", i == n - 1 ? '\n' : ' ' );
		}
	}
	return 0;
}