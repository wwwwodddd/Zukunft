#include <bits/stdc++.h>
using namespace std;
int n, m;
long long s;
int a[100020];
long long f[100020];
int q[100020], bb, ff;
int main()
{
	cin >> n >> m;
	q[ff++] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
		f[i] = f[q[bb]] + a[i];
		while (bb < ff && f[q[ff - 1]] > f[i])
		{
			ff--;
		}
		q[ff++] = i;
		while (bb < ff && q[bb] < i - m)
		{
			bb++;
		}
	}
	cout << s - f[q[bb]] << endl;
	return 0;
}