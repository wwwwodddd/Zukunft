#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[120];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				for (int k = j; k <= n; k++)
				{
					if (a[i] + a[j] == a[k])
					{
						z++;
					}
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}
