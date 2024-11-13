#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inv2 = 500000004;
const int inv3 = 333333336;
typedef long long ll;
int n, m;
ll C2(ll x)
{
	return x * (x - 1) % mod * inv2 % mod;
}
ll C3(ll x)
{
	return x * (x - 1) % mod * inv2 % mod * (x - 2) % mod * inv3 % mod;
}
ll g11[31];
ll g11cnt;
int points[40020];
int presum[40020];
inline int querypresum(int x) // < x
{
	int idx = lower_bound(points, points + 2 * n, x) - points;
	if (idx % 2 == 0)
	{
		return presum[idx];
	}
	else
	{
		return x + presum[idx];
	}
}
ll gao11(int t, int as, int qas, int ae, int qae, int bs, int qbs, int be, int qbe)
{
	if (t < 0)
	{
		return 0;
	}
	if (qae - qas < 1 || qbe - qbs < 1)
	{
		return 0;
	}
	if (ae - as == qae - qas && be - bs == qbe - qbs && g11[t] != -1)
	{
		return g11[t];
	}
	int am = (as + ae) / 2;
	int qam = querypresum(am);
	int bm = (bs + be) / 2;
	int qbm = querypresum(bm);
	g11cnt++;
	ll ac0 = qam - qas, ac1 = qae - qam;
	ll bc0 = qbm - qbs, bc1 = qbe - qbm;
	ll re = 0;
	if (m >> t & 1)
	{
		re = (ac0 * bc0 + ac1 * bc1) % mod;
		re = (re + gao11(t - 1, as, qas, am, qam, bm, qbm, be, qbe)) % mod;
		re = (re + gao11(t - 1, am, qam, ae, qae, bs, qbs, bm, qbm)) % mod;
	}
	else
	{
		re = (gao11(t - 1, as, qas, am, qam, bs, qbs, bm, qbm) + gao11(t - 1, am, qam, ae, qae, bm, qbm, be, qbe)) % mod;
	}
	if (ac0 == (1 << t) && ac1 == (1 << t) && bc0 == (1 << t) && bc1 == (1 << t))
	{
		g11[t] = re;
	}
	return re;
}
ll g12[31];
ll g12cnt;
ll gao12(int t, int as, int qas, int ae, int qae, int bs, int qbs, int be, int qbe)
{
	if (t < 0)
	{
		return 0;
	}
	if (qae - qas < 1 || qbe - qbs < 2)
	{
		return 0;
	}
	if (ae - as == qae - qas && be - bs == qbe - qbs && g12[t] != -1)
	{
		return g12[t];
	}
	int am = (as + ae) / 2;
	int qam = querypresum(am);
	int bm = (bs + be) / 2;
	int qbm = querypresum(bm);
	g12cnt++;
	ll ac0 = qam - qas, ac1 = qae - qam;
	ll bc0 = qbm - qbs, bc1 = qbe - qbm;
	ll re = 0;
	if (m >> t & 1)
	{
		re = (ac0 * C2(bc0) + ac1 * C2(bc1)) % mod;
		re = (re + bc0 * gao11(t - 1, as, qas, am, qam, bm, qbm, be, qbe)) % mod;
		re = (re + bc1 * gao11(t - 1, am, qam, ae, qae, bs, qbs, bm, qbm)) % mod;
		re = (re + gao12(t - 1, as, qas, am, qam, bm, qbm, be, qbe)) % mod;
		re = (re + gao12(t - 1, am, qam, ae, qae, bs, qbs, bm, qbm)) % mod;
	}
	else
	{
		re = (gao12(t - 1, as, qas, am, qam, bs, qbs, bm, qbm) + gao12(t - 1, am, qam, ae, qae, bm, qbm, be, qbe)) % mod;
	}
	if (ac0 == (1 << t) && ac1 == (1 << t) && bc0 == (1 << t) && bc1 == (1 << t))
	{
		g12[t] = re;
	}
	return re;
}
ll g3[31];
ll g3cnt;
ll gao3(int t, int as, int qas, int ae, int qae)
{
	if (t < 0)
	{
		return 0;
	}
	if (qae - qas < 3)
	{
		return 0;
	}
	int am = (as + ae) / 2;
	int qam = querypresum(am);
	g3cnt++;
	ll ac0 = qam - qas, ac1 = qae - qam;
	if (ac0 == (1 << t) && ac1 == (1 << t) && g3[t] != -1)
	{
		return g3[t];
	}
	ll re = 0;
	if (m >> t & 1)
	{
		re = (C3(ac0) + C3(ac1)) % mod;
		re = (re + gao12(t - 1, as, qas, am, qam, am, qam, ae, qae)) % mod;
		re = (re + gao12(t - 1, am, qam, ae, qae, as, qas, am, qam)) % mod;
	}
	else
	{
		re = (gao3(t - 1, as, qas, am, qam) + gao3(t - 1, am, qam, ae, qae)) % mod;
	}
	if (ac0 == (1 << t) && ac1 == (1 << t))
	{
		g3[t] = re;
	}
	return re;
}

int main()
{
	scanf("%d%d", &n, &m);
	m++;
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		points[i * 2] = x;
		points[i * 2 + 1] = y + 1;
		presum[i * 2 + 1] = presum[i * 2] - points[i * 2];
		presum[i * 2 + 2] = presum[i * 2 + 1] + points[i * 2 + 1];
	}
	memset(g11, -1, sizeof g11);
	memset(g12, -1, sizeof g12);
	memset(g3, -1, sizeof g3);
	printf("%lld\n", gao3(29, 0, querypresum(0), 1 << 30, querypresum(1 << 30)));
	return 0;
}