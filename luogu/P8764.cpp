#include <bits/stdc++.h>
using namespace std;
long long c[70][70];
int k;
int main()
{
	for (int i = 0; i < 62; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	long long n, z = 0;
	cin >> n >> k;
	n++;
	for (int i = 60; i >= 0 && k >= 0; i--)
	{
		if (n >> i & 1)
		{
			z += c[i][k];
			k--;
		}
	}
	cout << z << endl;
	return 0;
}