#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, z, s, a[1020];
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		a[x]++;
	}
	for (; s < n; s += m, z++)
	{
		m += a[s];
	}
	cout << z << endl;
	return 0;
}