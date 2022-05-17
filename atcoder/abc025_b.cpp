#include <bits/stdc++.h>
using namespace std;
int n, a, b, x, z;
string s;
int main()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> x;
		x = min(max(x, a), b);
		if (s[0] == 'W')
		{
			x = -x;
		}
		z += x;
	}
	if (z < 0)
	{
		cout << "West " << -z << endl;
	}
	else if (z > 0)
	{
		cout << "East " << z << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}