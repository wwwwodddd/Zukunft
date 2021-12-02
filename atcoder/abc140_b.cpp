#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int a[30];
int c[30];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		z += x;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i + 1] == a[i] + 1)
		{
			z += c[a[i]];
		}
	}
	cout << z << endl;
	return 0;
}
