#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[100020];
int h[1020];
int s[1020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j >= h[i]; j--)
		{
			f[j] = max(f[j], f[j - h[i]] + s[i]);
		}
	}
	cout << f[m] << endl;
	return 0;
}