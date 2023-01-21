#include <bits/stdc++.h>
using namespace std;
int n, m, p = 1;
int a[200020];
int b[200020];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		b[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for (int i = m; i > 0; i--)
	{
		swap(b[a[i]], b[a[i] + 1]);
	}
	for (int i = 1; i <= m; i++)
	{
		swap(b[a[i]], b[a[i] + 1]);
		cout << b[p] << endl;
		if (p == a[i] || p == a[i] + 1)
		{
			p = 2 * a[i] + 1 - p;
		}
	}
	return 0;
}
