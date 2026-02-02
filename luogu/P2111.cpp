#include <bits/stdc++.h>
using namespace std;
int n, p, q;
string s;
double f[60][60];
int main()
{
	cin >> n >> p >> q >> s;
	if (q == 0)
	{
		cout << "1.000" << endl;
	}
	else
	{
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				double c = p * 0.01;
				if (s[i] == '0')
				{
					c = 1 - c;
				}
				f[i + 1][j + 1] += f[i][j] * c;
				f[i + 1][j] += f[i][j] * (1 - c);
			}
		}
		double z = 0;
		for (int i = q; i <= n; i++)
		{
			z += f[n][i];
		}
		cout << fixed << setprecision(3) << z << endl;
	}
	return 0;
}