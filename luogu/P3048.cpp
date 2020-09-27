#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, l;
ll C(int n, int m)
{
	ll re = 1;
	for (int i = 0; i < m; i++)
	{
		re = re * (n - i) / (i + 1);
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	while (C(l, m) < n)
	{
		l++;
	}
	for (int i = l - 1; i >= 0; i--)
	{
		if (n > C(i, m))
		{
			n -= C(i, m);
			m--;
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
	return 0;
}