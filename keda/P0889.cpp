#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 200;
int v[201];
int f[201];
int main()
{
	f[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= n; j++)
			{
				f[j] += f[j - i];
			}
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	while (cin >> n)
	{
		cout << f[n] << endl;
	}
	return 0;
}