#include <bits/stdc++.h>
using namespace std;
int n;
int f[1000020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int d = i;
		f[i] = i;
		while (d > 0)
		{
			f[i] = min(f[i], f[i - d % 10] + 1);
			d /= 10;
		}
	}
	cout << f[n] << endl;
	return 0;
}