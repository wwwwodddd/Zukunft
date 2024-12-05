#include <bits/stdc++.h>
using namespace std;
int n, x;
int p[100020];
int q[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		p[x] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		q[i] = p[x];
	}
	int z = 0, x = n + 1;
	for (int i = n; i > 0; i--)
	{
		if (x > q[i])
		{
			x = q[i];
		}
		else
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}