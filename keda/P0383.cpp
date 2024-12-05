#include <bits/stdc++.h>
using namespace std;
int a[100020], n, x;
int f[100020]; // f[i] 长度为i的不下降子序列，最后一位最小是多少。
int main()
{
	while (cin >> x)
	{
		a[n++] = x;
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		// 找到最小的j，f[j] >= a[i], 执行f[j] = a[i];
		int p = lower_bound(f, f + n, a[i]) - f;
		f[p] = a[i];
	}
	int ans1 = lower_bound(f, f + n, 0x3f3f3f3f) - f;
	reverse(a, a + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		// 找到最小的j，f[j] > a[i], 执行f[j] = a[i];
		int p = upper_bound(f, f + n, a[i]) - f;
		f[p] = a[i];
	}
	int ans2 = lower_bound(f, f + n, 0x3f3f3f3f) - f;
	printf("%d\n", ans1);
}
