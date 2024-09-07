#include <bits/stdc++.h>
using namespace std;
int n, x, a, b;
bitset<10001> f;
int main()
{
	cin >> n >> x;
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = 0; j < b; j++)
		{
			f |= f << a;
		}
	}
	cout << (f[x] ? "Yes" : "No") << endl;
	return 0;
}