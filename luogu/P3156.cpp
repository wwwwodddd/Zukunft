#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int n, m, x;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		printf("%d\n", a[x]);
	}
	return 0;
}