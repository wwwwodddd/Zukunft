#include <bits/stdc++.h>
using namespace std;
int n, f, h, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (f <= h)
		{
			f = h;
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
