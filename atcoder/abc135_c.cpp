#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[100020];
long long z;
int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		int u = min(x, a[i]);
		z += u;
		x -= u;
		a[i] -= u;
		int v = min(x, a[i + 1]);
		z += v;
		x -= v;
		a[i + 1] -= v;
	}
	cout << z << endl;
	return 0;
}
