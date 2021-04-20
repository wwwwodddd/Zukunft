#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 3;
const long long sed = 133131;
int n, p;
struct Matrix {
	long long v[MAXN][MAXN];
	Matrix(){ memset(v, 0, sizeof v); }
	inline void read() {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%d", &v[i][j]);
	}
	void print()
	{
		printf("\n");
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%d ", v[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	inline long long hash() {
		int re = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				re = re * sed + v[i][j];
		return re;
	}
	inline Matrix operator *(const Matrix &o)const {
		Matrix re;
		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i) if(v[i][k])
				for(int j = 1; j <= n; ++j) if(o.v[k][j])
					re.v[i][j] = (re.v[i][j] + v[i][k] * o.v[k][j]) % p;
		return re;
	}
	inline bool operator ==(const Matrix &o)const {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(v[i][j] != o.v[i][j]) return 0;
		return 1;
	}
}Zero, One;
inline Matrix qpow(Matrix a, long long b) {
	Matrix re = One;
	while(b) {
		if(b & 1) re = re * a;
		a = a * a; b >>= 1;
	}
	return re;
}
long long gcd(long long x, long long y)
{
	return y > 0 ? gcd(y, x % y) : x;
}
long long lcm(long long x, long long y)
{
	return x / gcd(x, y) * y;
}
long long pre[1000020];
int v[1000020];
long long gao(int mod)
{
	if (mod % 2 == 0 || mod % 3 == 0)
	{
		return 0;
	}
	p = mod;
	long long ans1 = (p - 1LL) * p;
	long long ans2 = (p - 1LL) * (p + 1);
	n = 2;
	for (int i = 1; i <= n; One.v[i][i] = 1, ++i)
		;
	Matrix A;
	A.v[1][1] = 1;
	A.v[1][2] = 1;
	A.v[2][1] = 7;
	A.v[2][2] = 1;
	{
		int u = p - 1;
		while (u > 1)
		{
			if (qpow(qpow(A, ans1 / v[u]), ans2) == One)
			{
				ans1 /= v[u];
			}
			if (qpow(qpow(A, ans1), ans2 / v[u]) == One)
			{
				ans2 /= v[u];
			}
			u /= v[u];
		}
	}
	{
		int u = p + 1;
		while (u > 1)
		{
			if (qpow(qpow(A, ans1), ans2 / v[u]) == One)
			{
				ans2 /= v[u];
			}
			u /= v[u];
		}
	}
	{
		int u = p;
		while (u > 1)
		{
			if (qpow(qpow(A, ans1 / v[u]), ans2) == One)
			{
				ans1 /= v[u];
			}
			u /= v[u];
		}
	}
	assert(qpow(qpow(A, ans1), ans2) == One);
	return ans1 * ans2;
}
long long kao(int mod)
{
	if (mod % 2 == 0 || mod % 3 == 0)
	{
		return 0;
	}
	int x = mod;
	long long z = 1;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			int c = 0;
			while (x % i == 0)
			{
				x /= i;
				c++;
			}
			long long l = pre[i];
			for (int j = 1; j < c; j++)
			{
				l *= i;
			}
			z = lcm(z, l);
		}
	}
	if (x > 1)
	{
		z = lcm(z, pre[x]);
	}
	return z;
}
int main() {
	int limit = 1000000;
	for (int i = 2; i <= limit; i++)
	{
		if (i % 1000 == 0)
		{
			cout << i << endl;
		}
		if (v[i] == 0)
		{
			for (int j = i; j <= limit; j += i)
			{
				v[j] = i;
			}
			pre[i] = gao(i);
		}
	}
	long long ans = 0;
	for (int i = 2; i <= limit; i++)
	{
		ans += kao(i);
	}
	cout << ans << endl;
	return 0;
}