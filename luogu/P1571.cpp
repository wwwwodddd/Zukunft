#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[100020];
set<int> b;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		b.insert(x);
	}
	for (int i = 0; i < n; i++)
	{
		if (b.find(a[i]) != b.end())
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	return 0;
}