#include <bits/stdc++.h>
using namespace std;
int n;
unsigned f[4020];
int main()
{
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			f[j] = (f[j] + f[j - i]) % 2147483648;
		}
	}
	cout << (f[n] - 1) % 2147483648 << endl;
	return 0;
}