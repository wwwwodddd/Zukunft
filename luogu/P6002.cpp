#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1020];
int b[1020];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 1; i <= a[n - 1]; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			b[j] = a[j] % i;
			cnt += a[j] / i;
		}
		sort(b, b + n);
		int sum = 0;
		if (cnt >= k)
		{
			sum = i * k / 2;
		}
		else if (cnt >= k / 2)
		{
			sum = (cnt - k / 2) * i;
			if (n - (k - cnt) < 0)
			{
				continue;
			}
			for (int j = n - (k - cnt); j < n; j++)
			{
				sum += b[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
