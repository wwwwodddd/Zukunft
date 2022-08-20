#include <bits/stdc++.h>
using namespace std;
int n, k, q, x;
int a[220];
int main()
{
	cin >> n >> k >> q;
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i];
	}
	a[k + 1] = n + 1;
	for (int i = 0; i < q; i++)
	{
		cin >> x;
		if (a[x] + 1 < a[x + 1])
		{
			a[x]++;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
