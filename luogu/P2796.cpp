#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, x, y, z;
vector<int> a[100020];
int F(int x, int y)
{
	long long re = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			re = re * F(i, x) % p;
		}
	}
	z = (z + re) % p;
	return re + 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	F(1, 0);
	printf("%d\n", z);
	return 0;
}