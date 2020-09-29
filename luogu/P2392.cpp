#include <bits/stdc++.h>
using namespace std;
int gao(int n)
{
	bitset<1234> f;
	f[0] = 1;
	int s = 0, x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		f |= f << x;
		s += x;
	}
	s = (s + 1) / 2;
	while (!f[s])
	{
		s++;
	}
	return s;
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << gao(a) + gao(b) + gao(c) + gao(d) << endl;
	return 0;
}