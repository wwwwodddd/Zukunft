#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[100020];
int s[100020], ss;
int t[100020];
char o;
int main()
{
	s[0] = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &o);
		if (o == 'a')
		{
			scanf("%d", &x);
			s[++ss] = x;
			t[i] = ss;
			f[t[i]] = t[i - 1];
		}
		else if (o == 't')
		{
			scanf("%d", &x);
			t[i] = t[x - 1];
		}
		else
		{
			t[i] = f[t[i - 1]];
		}
		printf("%d\n", s[t[i]]);
	}
	return 0;
}