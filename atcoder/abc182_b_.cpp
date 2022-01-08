#include <bits/stdc++.h>
using namespace std;
int n, a[100];
int zc, zi;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= 1000; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] % i == 0)
			{
				c++;
			}
		}
		if (zc < c)
		{
			zc = c;
			zi = i;
		}
	}
	cout << zi << endl;
	return 0;
}
