#include <bits/stdc++.h>
using namespace std;
int n, d, z;
int a[20][20];
int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int s = 0;
			for (int k = 0; k < d; k++)
			{
				s += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
			}
			int r = sqrt(s);
			if (r * r == s)
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}
