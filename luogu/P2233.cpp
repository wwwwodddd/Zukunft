#include <bits/stdc++.h>
using namespace std;
int n;
int f[2][4];
int main()
{
	cin >> n;
	f[0][3] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i % 2][0] = (f[(i - 1) % 2][1]) % 1000;
		f[i % 2][1] = (f[(i - 1) % 2][0] + f[(i - 1) % 2][2]) % 1000;
		f[i % 2][2] = (f[(i - 1) % 2][1] + f[(i - 1) % 2][3]) % 1000;
		f[i % 2][3] = (f[(i - 1) % 2][2] + f[(i - 1) % 2][2]) % 1000;
	}
	cout << (f[(n - 1) % 2][0] * 2) % 1000 << endl;
	return 0;
}
