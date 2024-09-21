#include <bits/stdc++.h>
using namespace std;
int a[100020], n, x;
int f[100020];
int main()
{
	while (cin >> x)
	{
		a[n++] = x;
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		*lower_bound(f, f + n, a[i]) = a[i];
	}
	int ans1 = lower_bound(f, f + n, 0x3f3f3f3f) - f;
	reverse(a, a + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		*upper_bound(f, f + n, a[i]) = a[i];
	}
	int ans2 = lower_bound(f, f + n, 0x3f3f3f3f) - f;
	printf("%d\n%d\n", ans2, ans1);
}