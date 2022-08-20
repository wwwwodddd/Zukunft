#include <bits/stdc++.h>
using namespace std;
int n;
bitset<3000> a[3000];
long long z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i][n - j - 1])
			{
				z += (a[i] & a[j]).count();
			}
		}
	}
	cout << z / 3 << endl;
	return 0;
}
