#include <bits/stdc++.h>
using namespace std;
int n, x, l, s, z = 1;
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		s += l;
		if (s <= x)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
