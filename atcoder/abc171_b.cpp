#include <bits/stdc++.h>
using namespace std;
int n, m, z, a[1000];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		z += a[i];
	}
	cout << z << endl;
	return 0;
}
