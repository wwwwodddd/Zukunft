#include<stdio.h>
#include<iostream>
#include<string.h>
#define C(x) __builtin_popcount(x)
using namespace std;
int g[60][26],f[60][32780];
char s[20][60];
int z[32780], t[20], c[20][20];
int tt,n,q,l,mo=1000003;
int dp(int b) {
	int z = 1;
	for (int i = 0; i < l; i++) {
		char c = '?';
		for (int j = 0; j < n; j++) {
			if ((b >> j & 1) && s[j][i] != '?') {
				if (c != '?' && c != s[j][i]) {
					return 0;
				}
				c = s[j][i];
			}
		}
		if (c == '?') {
			z = z * 26 % mo;
		}
	}
	return z;
}
int main()
{
	for (int i = 0; i < 20; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
		}
	}
	for(scanf("%d",&tt);tt--;)
	{
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		l = strlen(s[0]);
		memset(t, 0, sizeof t);
		t[q] = 1;
		for (int i = q + 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				t[i] -= (long long)t[j] * c[i][j] % mo;
				if (t[i] < 0) {
					t[i] += mo;
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < 1 << n; i++) {
			ans = (ans + (long long)t[C(i)] * dp(i)) % mo;
		}
		printf("%lld\n", ans);
	}
	return 0;   
}