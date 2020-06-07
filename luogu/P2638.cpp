#include <bits/stdc++.h>
using namespace std;
long long c[51][51];
int main()
{
	for (int i = 0; i <= 50; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	int n, a, b;
	cin >> n >> a >> b;
	cout << c[a + n][n] * c[b + n][n] << endl;
	return 0;
}