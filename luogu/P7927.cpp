#include <bits/stdc++.h>
using namespace std;
int n, t, a, b;
int z[2], l[9];
int main()
{
	memset(l, 0xc0, sizeof l);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> a >> b;
		z[a / 5] += 100;
		if (t - l[a] <= 10)
		{
			z[a / 5] += 50;
		}
		l[a] = t;
	}
	cout << z[0] << " " << z[1] << endl;
	return 0;
}
