#include <bits/stdc++.h>
using namespace std;
int n, z = 1e9;
long long m, s;
int a[100020];
int b[100020];
int q[100020], bb, ff;
int main()
{
	cin >> n >> m;
	for (int i = 0, j = 0; j < n; j++)
	{
		cin >> a[j] >> b[j];
		s += a[j];
		while (bb < ff && b[q[ff - 1]] < b[j])
		{
			ff--;
		}
		q[ff++] = j;
		while (s - a[i] >= m)
		{
			s -= a[i++];
		}
		while (bb < ff && q[bb] < i)
		{
			bb++;
		}
		if (s >= m)
		{
			z = min(z, b[q[bb]]);
		}
	}
	cout << z << endl;
	return 0;
}