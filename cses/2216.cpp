#include <bits/stdc++.h>
using namespace std;
int n, x, z = 1;
int p[200020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		p[x] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (p[i] < p[i - 1])
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
