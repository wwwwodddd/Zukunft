#include <bits/stdc++.h>
using namespace std;
int n, d, a, p = 1e9;
int v[200020];
long long z, s;
int main()
{
	cin >> n >> d;
	for (int i = 1; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> a;
		p = min(p, a);
		s += v[i];
		if (s > 0)
		{
			long long t = (s + d - 1) / d;
			z += t * p;
			s -= t * d;
		}
	}
	cout << z << endl;
	return 0;
}