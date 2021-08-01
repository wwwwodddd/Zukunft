#include <bits/stdc++.h>
using namespace std;
int n, m, w, v;
long long f[100001];
int main()
{
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> w >> v;
		for (int j = 100000; j >= v; j--)
		{
			f[j] = min(f[j], f[j - v] + w);
		}
	}
	for (int j = 100000; j >= 0; j--)
	{
		if (f[j] <= m)
		{
			cout << j << endl;
			break;
		}
	}
	return 0;
}