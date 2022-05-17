#include <bits/stdc++.h>
using namespace std;
int n, x, s;
int f[100020];
int main()
{
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		for (int j = s; j >= x; j--)
		{
			f[j] |= f[j - x];
		}
	}
	for (int i = s / 2; i >= 0; i--)
	{
		if (f[i])
		{
			cout << s - i << endl;
			break;
		}
	}
	return 0;
}
