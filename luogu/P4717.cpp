#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const long long inv2 = 499122177;
int n;
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
	for (int i = 1; i < n; i <<= 1)
	{
		for (int j = 0; j < n; j++)
		{
			if (j & i)
			{
				op(a[j ^ i], a[j]);
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	n = 1 << n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}
	memcpy(a, A, sizeof a);
	memcpy(b, B, sizeof b);
	gao(a, );
	gao(b, or0);
	for (int i = 0; i < n; i++)
	{
		a[i] = (long long)a[i] * b[i] % mod;
	}
	gao(a, or1);
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	memcpy(a, A, sizeof a);
	memcpy(b, B, sizeof b);
	gao(a, and0);
	gao(b, and0);
	for (int i = 0; i < n; i++)
	{
		a[i] = (long long)a[i] * b[i] % mod;
	}
	gao(a, and1);
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	memcpy(a, A, sizeof a);
	memcpy(b, B, sizeof b);
	gao(a, xor0);
	gao(b, xor0);
	for (int i = 0; i < n; i++)
	{
		a[i] = (long long)a[i] * b[i] % mod;
	}
	gao(a, xor1);
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}