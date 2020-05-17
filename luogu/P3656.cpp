#include <bits/stdc++.h>
using namespace std;
int n;
long long r, s, z;
int a[100020];
int b[100020];
int p[100020];
int q[100020];
int c[100020];
void R(int x, int y)
{
	assert(x > 0);
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int G(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		q[b[i]] = i;
		R(p[b[i]], 1);
		r += i - G(p[b[i]]);
	}
	for (int i = 1; i <= n; i++)
	{
		s += n + 1 - 2 * q[a[i]];
		z = min(z, s);
	}
	for (int i = 1; i <= n; i++)
	{
		s += n + 1 - 2 * p[b[i]];
		z = min(z, s);
	}
	cout << r + z << endl;
	return 0;
}