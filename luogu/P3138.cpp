#include <bits/stdc++.h>
using namespace std;
int n;
int x[1020];
int y[1020];
int xl[1020], xc;
int yl[1020], yc;
int s[1020][1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		xl[i] = x[i];
		yl[i] = y[i];
	}
	sort(xl, xl + n);
	sort(yl, yl + n);
	xc = unique(xl, xl + n) - xl;
	yc = unique(yl, yl + n) - yl;
	for (int i = 0; i < n; i++)
	{
		x[i] = lower_bound(xl, xl + xc, x[i]) - xl + 1;
		y[i] = lower_bound(yl, yl + yc, y[i]) - yl + 1;
		s[x[i]][y[i]]++;
	}
	for (int i = 1; i <= xc; i++)
	{
		for (int j = 1; j <= yc; j++)
		{
			s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}
	int z = n;
	for (int i = 0; i <= xc; i++)
	{
		for (int j = 0; j <= yc; j++)
		{
			int lu = s[i][j];
			int ru = s[i][yc] - lu;
			int ld = s[xc][j] - lu;
			int rd = s[xc][yc] - ru - ld - lu;
			z = min(z, max(max(lu, ru), max(ld, rd)));
		}
	}
	cout << z << endl;
	return 0;
}