#include <bits/stdc++.h>
using namespace std;
int n, x;
bitset<100001> f;
int main()
{
	f[0] = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		f |= f << x;
	}
	cout << f.count() - 1 << endl;
	for (int i = 1; i < 100001; i++)
	{
		if (f[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}