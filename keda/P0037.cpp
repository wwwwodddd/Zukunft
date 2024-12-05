#include <bits/stdc++.h>
using namespace std;
int n, c, x;
bitset<1000> f;
int main()
{
	cin >> n >> c;
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		f |= f << x;
	}
	while (!f[c])
	{
		c--;
	}
	cout << c << endl;
	return 0;
}