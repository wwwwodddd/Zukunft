#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
int n;
long long z;
bitset<3000> a[3000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			long long c = (a[i] & a[j]).count();
			z += c * (c - 1) / 2;
		}
	}
	cout << z << endl;
	return 0;
}