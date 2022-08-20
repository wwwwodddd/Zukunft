#include <bits/stdc++.h>
using namespace std;
int n;
int x[200020];
int c[200020];
int v[200020];
long long z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (v[j] == 0)
		{
			v[j] = i;
			j = x[j];
		}
		if (v[j] == i)
		{
			int w = c[j];
			for (int k = x[j]; k != j; k = x[k])
			{
				w = min(w, c[k]);
			}
			z += w;
		}
	}
	cout << z << endl;
	return 0;
}
