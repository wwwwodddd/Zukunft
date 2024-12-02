#include <bits/stdc++.h>
using namespace std;
int n;
int h[100020];
int f[100020];
int g[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		if (h[i] < h[i - 1])
		{
			f[i] = 1;
		}
		else
		{
			f[i] = f[i - 1] + 1;
		}
	}
	int z = 0;
	for (int i = n; i > 0; i--)
	{
		if (h[i] < h[i + 1])
		{
			g[i] = 1;
		}
		else
		{
			g[i] = g[i + 1] + 1;
		}
		z = max(z, f[i] + g[i] - 1);
	}
	cout << z << endl;
	return 0;
}