#include <bits/stdc++.h>
using namespace std;
int n, x, z;
map<int, int> c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	for (pair<int, int> i: c)
	{
		if (i.second & 1)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
