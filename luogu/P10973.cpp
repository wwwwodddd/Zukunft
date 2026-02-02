#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100];
bitset<100001> f;
int main()
{
	while (cin >> n >> m, n)
	{
		f.reset();
		f[0] = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			int c;
			cin >> c;
			for (int j = 1; j < c; j *= 2)
			{
				f |= f << (j * a[i]);
				c -= j;
			}
			f |= f << (c * a[i]);
		}
		int z = 0;
		for (int i = 1; i <= m; i++)
		{
			z += f[i];
		}
		cout << z << endl;
	}
	return 0;
}