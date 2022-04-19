#include <bits/stdc++.h>
using namespace std;
int n, l, z;
long x[320];
long y[320];
int xian(int i, int j, int k)
{
	return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]) == 0;
}
int main()
{
	cin >> n >> l;
	if (l == 1)
	{
		cout << "Infinity" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int c = 0;
			for (int k = 0; k < n; k++)
			{
				if (xian(i, j, k))
				{
					if (k != i && k < j)
					{
						c = 0;
						break;
					}
					c++;
				}
			}
			if (c >= l)
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}
