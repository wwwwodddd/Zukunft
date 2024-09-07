#include <bits/stdc++.h>
using namespace std;
int m, n, x;
int f[10001];
int main()
{
	cin >> m >> n;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = x; j <= m; j++)
		{
			f[j] = min(f[j], f[j - x] + 1);
		}
	}
	if (f[m] > 1e9)
	{
		cout << "Roberta acknowledges defeat." << endl;
	}
	else
	{
		cout << "Roberta wins in " << f[m] << " strokes." << endl;
	}
	return 0;
}