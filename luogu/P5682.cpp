#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int gao()
{
	sort(a, a + n);
	n = unique(a, a + n) - a;
	if (n < 2)
	{
		return -1;
	}
	else if (n == 2)
	{
		return a[n - 1] % a[n - 2];
	}
	else
	{
		return max(a[n - 3], a[n - 1] % a[n - 2]);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d\n", gao());
	return 0;
}