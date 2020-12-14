#include <bits/stdc++.h>
using namespace std;
int n, a[120], z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n - 2; i >= 0; i--)
	{
		int t = min(a[i], a[i + 1] - 1);
		z += a[i] - t;
		a[i] = t;
	}
	printf("%d\n", z);
	return 0;
}