#include <bits/stdc++.h>
using namespace std;
long long n, m;
int a[1000020];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	long long k = 0;
	while (k * (k + 1) / 2 <= m)
	{
		k++;
	}
	reverse(a + 1, a + k + 1);
	m -= k * (k - 1) / 2;
	rotate(a + k + 1 - m, a + k + 1, a + k + 2);
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}