#include <bits/stdc++.h>
using namespace std;
int n;
int f[3020];
long long x[3020];
long long y[3020];
long long r[3020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main()
{
	cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
		f[i] = i;
		for (int j = 0; j < i; j++)
		{
			long long d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if ((r[i] - r[j]) * (r[i] - r[j]) <= d && d <= (r[i] + r[j]) * (r[i] + r[j]))
			{
				U(i, j);
			}
		}
	}
	cout << (F(0) == F(1) ? "Yes" : "No") << endl;
	return 0;
}
