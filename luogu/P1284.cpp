#include <bits/stdc++.h>
using namespace std;
int n, p, x;
bool f[1620][1620];
int main()
{
	cin >> n;
	f[0][0] = true;
	for (int k = 0; k < n; k++)
	{
		cin >> x;
		for (int i = p; i >= 0; i--)
		{
			for (int j = p; j >= 0; j--)
			{
				f[i + x][j] |= f[i][j];
				f[i][j + x] |= f[i][j];
			}
		}
		p += x;
	}
	double q = p * 0.5;
	int z = -1;
	for (int i = 1; i < p; i++)
	{
		for (int j = 1; i + j < p; j++)
		{
			int k = p - i - j;
			if (f[i][j] && i + j > k && i + k > j && j + k > i)
			{
				z = max(z, int(sqrt(q * (q - i) * (q - j) * (q - k)) * 100));
			}
		}
	}
	cout << z << endl;
	return 0;
}