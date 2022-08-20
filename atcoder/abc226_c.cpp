#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[200020];
int v[200020];
vector<int> a[200020];
long long z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> m;
		a[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	v[n] = 1;
	for (int i = n; i > 0; i--)
	{
		if (v[i])
		{
			z += t[i];
			for (int j : a[i])
			{
				v[j] = 1;
			}
		}
	}
	cout << z << endl;
	return 0;
}
