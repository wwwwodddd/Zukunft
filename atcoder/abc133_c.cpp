#include <bits/stdc++.h>
using namespace std;
const int p = 2019;
int l, r, z = p;
int main()
{
	cin >> l >> r;
	r = min(r, l + p)
	for (int i = l; i <= r && z; i++)
	{
		for (int j = i + 1; j <= r && z; j++)
		{
			z = min(z, i * j % p);
		}
	}
	cout << z << endl;
	return 0;
}
