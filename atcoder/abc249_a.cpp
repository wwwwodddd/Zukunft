#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, x, u, v;
int main()
{
	cin >> a >> b >> c >> d >> e >> f >> x;
	u = (x / (a + c) * a + min(a, x % (a + c))) * b;
	v = (x / (d + f) * d + min(d, x % (d + f))) * e;
	if (u > v)
	{
		cout << "Takahashi" << endl;
	}
	else if (u < v)
	{
		cout << "Aoki" << endl;
	}
	else
	{
		cout << "Draw" << endl;
	}
	return 0;
}
