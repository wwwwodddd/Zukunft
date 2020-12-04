#include<bits/stdc++.h>
using namespace std;
int n, m, p1, s1, s2, pos;
long long a[100020], ans, sum;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	scanf("%d%d%d%d",&m,&p1,&s1,&s2);
	a[p1] += s1;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i] * (m - i);
	}
	ans = abs(sum) + 1;
	for (int i = 1; i <= n; i++)
	{
		if (ans > abs(sum + (long long)(m - i) * s2))
		{
			ans = abs(sum + (long long)(m - i) * s2);
			pos = i;
		}
	}
	printf("%d\n", pos);
	return 0;
}