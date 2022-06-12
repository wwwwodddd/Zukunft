#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int v[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v[x] = 1;
		while (v[z])
		{
			z++;
		}
		cout << z << endl;
	}
	return 0;
}
