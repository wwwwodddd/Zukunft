#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[50020];
int v[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v[a[i]] = 1;
	}
	sort(a, a + n / 2);
	sort(a + n / 2, a + n);
	for (int i = n / 2 - 1, j = 2 * n; i >= 0; i--)
	{
		while (v[j])
		{
			j--;
		}
		if (j > a[i])
		{
			j--;
			ans++;
		}
	}
	for (int i = n / 2, j = 1; i < n; i++)
	{
		while (v[j])
		{
			j++;
		}
		if (j < a[i])
		{
			j++;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}