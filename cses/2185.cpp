#include <bits/stdc++.h>
using namespace std;
long long n, z;
int m;
long long a[30];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < 1 << m; i++)
	{
		long long t = n, s = -1;
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
			{
				t /= a[j];
				s = -s;
			}
		}
		z += t * s;
	}
	cout << z << endl;
	return 0;
}