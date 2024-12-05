#include <bits/stdc++.h>
using namespace std;
int t, n;
int b[] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688};
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		if (n <= 14)
		{
			cout << b[n] << endl;
		}
		else
		{
			int d = (n - 14) / 7;
			n -= d * 7; // 14 <= n <= 20
			cout << b[n];
			for (int j = 0; j < d; j++)
			{
				cout << 8;
			}
			cout << endl;
		}
	}
	return 0;
}