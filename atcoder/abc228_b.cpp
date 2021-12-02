#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int a[100020];
int v[100020];
int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	while (!v[x])
	{
		v[x] = 1;
		z++;
		x = a[x];
	}
	cout << z <<endl;
	return 0;
}
