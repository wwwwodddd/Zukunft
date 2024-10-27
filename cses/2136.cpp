#include <bits/stdc++.h>
using namespace std;
int n, m, z;
char s[40];
int a[20020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i] |= (s[j] - '0') << j;
		}
	}
	z = m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			z = min(z, __builtin_popcount(a[i] ^ a[j]));
		}
	}
	cout << z << endl;
	return 0;
}