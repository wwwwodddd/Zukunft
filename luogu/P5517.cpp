#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int mod = 1000000007;
const int inv32 = 281250002;
const int l = 65536;
ull sd;
int op;
inline ull ull_rand()
{
	sd ^= sd << 43;
	sd ^= sd >> 29;
	sd ^= sd << 34;
	return sd;
}
int t;
ull z;
ull a[l + 1];
ull b[l + 1];
int main()
{
	scanf("%d%llu%d", &t, &sd, &op);
	b[0] = a[0] = 1;
	for(int i = 0; i < l; i++)
	{
		a[i + 1] = a[i] * 3 % mod;
	}
	for(int i = 0; i < l; i++)
	{
		b[i + 1] = b[i] * a[l] % mod;
	}
	for (int tt = 0; tt < t; tt++)
	{
		ull n = ull_rand();
		if (op == 0)
		{
			n = n % USHRT_MAX + 1;
		}
		if (op == 1)
		{
			n = n % UINT_MAX + 1; 
		}
		int m = n % (mod - 1);
		z ^= ((n % mod * 36 - 117 + mod) % mod * b[m / l] % mod * a[m % l] % mod + (n & 1 ? 51 : 21)) % mod * inv32 % mod;
	}
	printf("%llu\n", z);
	return 0;
}