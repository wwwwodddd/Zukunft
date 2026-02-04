#include <bits/stdc++.h>
using namespace std;
int f[100020];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			f[i] = min(f[i], f[i - j * j] + 1);
		}
	}
	cout << f[n] << endl;
	return 0;
}