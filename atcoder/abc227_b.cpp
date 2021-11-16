#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int v[81509];
int main()
{
	for (int a = 1; a < 143; a++)
	{
		for (int b = 1; b <= a; b++)
		{
			v[4 * a * b + 3 * a + 3 * b] = 1;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z += !v[x];
	}
	cout << z << endl;
	return 0;
}
