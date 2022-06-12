#include <bits/stdc++.h>
using namespace std;
int n, c[31][31];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
		for (int j = 0; j <= i; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
