#include <bits/stdc++.h>
using namespace std;
int n, k, m, x, z;
int v[101];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			v[x]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		z += !v[i];
	}
	cout << z << endl;
	return 0;
}
