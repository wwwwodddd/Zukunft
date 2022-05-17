#include <bits/stdc++.h>
using namespace std;
int n, h, l, z, f;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (l >= h)
		{
			z = max(z, ++f);			
		}
		else
		{
			f = 0;
		}
		l = h;
	}
	cout << z << endl;
	return 0;
}
