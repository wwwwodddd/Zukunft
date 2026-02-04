#include <bits/stdc++.h>
using namespace std;
int n, x, s;
bitset<20010> f;
int main()
{
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		f |= f << x;
	}
	if (s % 2 == 0 && f[s / 2])
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}