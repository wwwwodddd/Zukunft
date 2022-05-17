#include <bits/stdc++.h>
using namespace std;
int n, x, p, z;
int main()
{
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x < p)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
