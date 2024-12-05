#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
int f[200020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		*upper_bound(f, f + n, a[i]) = a[i];
	}
	cout << (lower_bound(f, f + n, 0x3f3f3f3f) - f) << endl;
	return 0;
}