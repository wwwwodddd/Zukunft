#include <bits/stdc++.h>
using namespace std;
int n, z;
int x[320];
int y[320];
long long det(long long x1, long long y1, long long x2, long long y2)
{
	return x1 * y2 - x2 * y1;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (det(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i]) != 0)
				{
					z++;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
