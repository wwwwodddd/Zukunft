#include <bits/stdc++.h>
using namespace std;
const int B = 31;
const int p = 998244353;
int n, m, tt = 1, x;
int t[5000020][2];
int c[5000020];
long long b[300020];
void ins(int x)
{
	int r = 1;
	for (int i = B; i--;)
	{
		if (t[r][x >> i & 1] == 0)
		{
			t[r][x >> i & 1] = ++tt;
		}
		r = t[r][x >> i & 1];
		c[r]++;
	}
}
long long zuo2(int r1, int r2, int d)
{
	long long z = 0;
	if (r1 == 0)
	{
		return b[c[r2]] - 1;
	}
	if (r2 == 0)
	{
		return b[c[r1]] - 1;
	}
	if (d < 0)
	{
		return b[c[r1]] - 1 + b[c[r2]] - 1;
	}
	if (m >> d & 1)
	{
		z = (z + (zuo2(t[r1][0], t[r2][1], d - 1) + 1LL) * (zuo2(t[r1][1], t[r2][0], d - 1) + 1LL) - 1) % p;
	}
	else
	{
		z = (z + (b[c[t[r1][0]]] - 1LL) * (b[c[t[r1][1]]] - 1LL)) % p;
		z = (z + (b[c[t[r2][0]]] - 1LL) * (b[c[t[r2][1]]] - 1LL)) % p;
		z = (z + zuo2(t[r1][0], t[r2][0], d - 1) + zuo2(t[r1][1], t[r2][1], d - 1)) % p;
	}
	return z;
}
long long zuo1(int r, int d)
{
	long long z = 0;
	if (r == 0)
	{
		return 0;
	}
	if (d < 0)
	{
		return 0;
	}
	if (m >> d & 1)
	{
		z = zuo2(t[r][0], t[r][1], d - 1);
	}
	else
	{
		z = (zuo1(t[r][0], d - 1) + zuo1(t[r][1], d - 1)) % p;
	}
	return z;
}
int main()
{
	cin >> n >> m;
	m++;
	for (int i = b[0] = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * 2 % p;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ins(x);
	}
	cout << zuo1(1, B - 1) << endl;
	return 0;
}