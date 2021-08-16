#include <bits/stdc++.h>
using namespace std;
int a[200020];
int b[200020];
int n, m, z = 1e9;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0, j = 0; i < n && j < m; a[i] < b[j] ? i++ : j++)
	{
		z = min(z, abs(a[i] - b[j]));
	}
	cout << z << endl;
	return 0;
}
