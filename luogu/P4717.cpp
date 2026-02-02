#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const long long inv2 = 499122177;
int n, m;
int A[131073];
int B[131073];
int a[131073];
int b[131073];
void or0(int &x, int &y)
{
	y = (y + x) % mod;
}
void or1(int &x, int &y)
{
	y = (y + mod - x) % mod;
}
void and0(int &x, int &y)
{
	x = (x + y) % mod;
}
void and1(int &x, int &y)
{
	x = (x + mod - y) % mod;
}
void xor0(int &x, int &y)
{
	int u = (x + y) % mod, v = (x + mod - y) % mod;
	x = u;
	y = v;
}
void xor1(int &x, int &y)
{
	int u = (x + y) * inv2 % mod, v = (x + mod - y) * inv2 % mod;
	x = u;
	y = v;
}
void gao(int a[], void op(int &, int &))
{
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i >> j & 1)
			{
				op(a[i ^ 1 << j], a[i]);
			}
		}
	}
}
void work(void op0(int &, int &), void op1(int &, int &))
{
	memcpy(a, A, sizeof a);
	memcpy(b, B, sizeof b);
	gao(a, op0);
	gao(b, op0);
	for (int i = 0; i < n; i++)
	{
		a[i] = (long long)a[i] * b[i] % mod;
	}
	gao(a, op1);
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
}
int main()
{
	scanf("%d", &m);
	n = 1 << m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}
	work(or0, or1);
	work(and0, and1);
	work(xor0, xor1);
	return 0;
}