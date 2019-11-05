#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p = 1000004321;
int c = 10;
int N;
ll a[101][101];
ll b[101][101];
int v[1000];
int g[1000];
void mul(ll a[101][101], ll b[101][101]) {
	ll c[101][101] = {};
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < N; j++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, c, sizeof c);
}
int simplify(int i) {
	int x = i / c / c;
	int y = i / c % c;
	int z = i % c;
	if (x < 9) {
		if (y == z) {
			return -1;
		}
		int c = 2;
		if (y >= 2) {
			y = c;
			c++;
		}
		if (z >= 2) {
			z = c;
		}
	} else {
		if (y != z) {
			return -1;
		}
		if (y >= 2) {
			y = 2;
			z = 2;
		}
	}
	return x * c * c + y * c + z;
}
ll work(ll n) {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	for (int i = 0; i < N; i++) {
		a[i][i] = 1;
	}
	for (int i = 0; i < 10 * c * c; i++) {
		int enc0 = simplify(i);
		if (enc0 == -1) {
			continue;
		}
		int x = i / c / c;
		int y = i / c % c;
		int z = i % c;
		for (int j = 0; j < c; j++) {
			if (j != y && j != z) {
				int enc1 = 9 * c * c + j * c + j;
//				if (enc0 == 6) {
//					printf("trans %d %d %d %d\n", i, enc0, enc1, b[g[enc0]][g[enc1]]);
//				}
				assert(enc1 != -1);
				if (enc1 == v[enc1]) {
					b[g[enc0]][g[enc1]]++;
				}
			}
		}
		if (x == 9) {
			for (int j = 0; j < c; j++) {
				for (int k = 0; k < c; k++) {
					if (j != k && j != y && k != y) {
						int enc1 = j * c + k;
						assert(enc1 != -1);
						if (enc1 == v[enc1]) {
							b[g[enc0]][g[enc1]]++;
						}
					}
				}
			}
		} else {
			if (x / 3 < 2 && x % 3 < 2) {
				int enc1 = (x + 4) * c * c + y * c + z;
				assert(enc1 != -1);
				if (enc1 == v[enc1]) {
					b[g[enc0]][g[enc1]]++;
				}
			}
			for (int j = 0; j < c; j++) {
				if (j != y && j != z) {
					if (x % 3 < 2) {
						int enc1 = (x % 3 + 1) * c * c + j * c + z;
						assert(enc1 != -1);
						if (enc1 == v[enc1]) {
							b[g[enc0]][g[enc1]]++;
						}
					}
					if (x / 3 < 2) {
						int enc1 = (x / 3 * 3 + 3) * c * c + y * c + j;
						assert(enc1 != -1);
						if (enc1 == v[enc1]) {
							b[g[enc0]][g[enc1]]++;
						}
					}
				}
			}
		}
	}
	
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	
	for (int i = 0; i < 10 * c * c; i++) {
		if (g[i] == 17) {
			int x = i / c / c;
			int y = i / c % c;
			int z = i % c;
//			cerr << "decode " << i << ' ' << x << ' ' << y << ' ' << z << endl;
		}
	}
	int importantenc = v[17];
	//	printf("importantenc %d %d %d %d\n", importantenc, importantenc / c / c, importantenc / c % c, importantenc % c);
	for (int i = 0; i < 10 * c * c; i++) {
		if (v[i] == i && a[g[importantenc]][g[i]] != 0) {
			assert(i == simplify(i));
			int x = i / c / c;
			int y = i / c % c;
			int z = i % c;
//			printf("%d %d %d %d: %lld\n", i, x, y, z, a[g[importantenc]][g[i]]);
		}
	}
	cerr << endl;
	int enc = simplify(9 * c * c);
	ll ans = a[g[enc]][g[enc]] * c;
//	cerr << "1x2 " << enc << ' ' << g[enc] << ' ' << a[g[enc]][g[enc]] << endl;
	for (int i = 0; i < 9; i++) {
		int enc = simplify(i * c * c + 1);
		ans += a[g[enc]][g[enc]] * c * (c - 1);
//		cerr << i * c * c + 1 << ' ' << enc << ' ' << a[g[enc]][g[enc]] << endl;
	}
	return ans % p;
}
ll pw(ll x, ll y) {
	x %= p;
	ll re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	memset(v, -1, sizeof v);
	memset(g, -1, sizeof g);
	for (int i = 0; i < 10 * c * c; i++) {
		int enc = simplify(i);
		if (enc != -1) {
			v[i] = enc;
		}
	}
	for (int i = 0; i < 10 * c * c; i++) {
		if (v[i] == i) {
			g[i] = N++;
		}
	}
	cerr << "number of states " << N << endl;
	ll n = 10004003002001;
	ll ans = work(n) * pw(n, p - 2) % p;
	printf("answer %lld\n", ans);
	return 0;
}
