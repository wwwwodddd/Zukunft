#include <bits/stdc++.h>
using namespace std;
int n, m, x, z;
int v[100020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v[x] = 1;
	}
	for (int i = 1; i < 100010; i++)
	{
		for (int j = i; j < 100010; j += i)
		{
			v[i] |= v[j];
		}
	}
	v[1] = 0;
	for (int i = 1; i < 100010; i++)
	{
		for (int j = i; j < 100010; j += i)
		{
			v[j] |= v[i];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (v[i] == 0)
		{
			z++;
		}
	}
	cout << z << endl;
	for (int i = 1; i <= m; i++)
	{
		if (v[i] == 0)
		{
			cout << i << endl;
		}
	}
}
