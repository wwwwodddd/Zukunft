#include <bits/stdc++.h>
using namespace std;
int n, x, z, s, l;
int main()
{
	cin >> n >> l;
	s = l;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (l < x)
		{
			z = max(z, x - s);
		}
		else
		{
			s = x;
		}
		l = x;
	}
	cout << z << endl;
	return 0;
}
