#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
int s[100020];
char c[100020];
int main()
{
	scanf("%d%d%s", &n, &q, c);
	for (int i = 0; i < n; i++)
	{
		s[i + 1] = s[i] + c[i] - 96;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}
