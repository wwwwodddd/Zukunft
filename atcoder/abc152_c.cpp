#include <bits/stdc++.h>
using namespace std;
int n, f, x, z = 1;
int main()
{
	cin >> n >> f;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (f > x)
		{
			f = x;
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
