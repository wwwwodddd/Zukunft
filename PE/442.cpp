#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char c[300];
long long f[300][2000];
int g[2000];
int t[2000][10], tt;
int v[2000];
int maxflag = 0;
namespace IchLiebeDich {
	const int L = 40;
	int a[L + 10];
	int l;
	void mul(int x) {
		for (int i = 0; i < L + 5; i++) {
			a[i] *= x;
		}
		for (int i = 0; i < L + 5; i++) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10; 
		}
		l = 0;
		for (int i = 0; i < L + 5; i++) {
			if (a[i] > 0) {
				l = i + 1;
			}
		}
	}

	void ins() {
		int p = 0;
		for (int i = l - 1; i >= 0; i--) {
			if (t[p][a[i]] == 0) {
				t[p][a[i]] = ++tt;
			}
			p = t[p][a[i]];
		}
		v[p] = 1;
	}

	void print() {
		for (int i = 0; i <= tt; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d ", t[i][j]);
			}
			printf("%d %d\n", i, v[i]);
		}
	}

	void work(int x, int flag) {
		memset(a, 0, sizeof a);
		l = 1;
		a[0] = 1;
		while (true) {
			mul(x);
			ins();
			if (l > L) {
				break;
			}
		}
	}

	void build() {
		queue<int> q;
		q.push(0);
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < 10; i++) {
				if (t[u][i] > 0) {
					q.push(t[u][i]);
					if (u > 0) {
						g[t[u][i]] = t[g[u]][i];
						v[t[u][i]] |= v[g[t[u][i]]];
					}
				} else {
					t[u][i] = t[g[u]][i];
				}
			}
		}
	}

	void ILoveYou() {
//		work(2, 1);
//		work(6, 2);
		work(11, 1);
		build();
//		printf("%d %d\n", tt, maxflag);
//		print();
	}
}

long long solve(long long x) {
	sprintf(c, "%lld", x);
	int n = strlen(c);
	reverse(c, c + n);
	long long ans = 0;
	int current = 0;
	int mask = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < c[i] - '0'; j++) {
			ans += f[i][t[current][j]];
		}
		current = t[current][c[i] - '0'];
	}
	return ans;
}

int main() {
	memset(t, 0, sizeof t);
	memset(v, 0, sizeof v);
	tt = 0;
	IchLiebeDich::ILoveYou();
	memset(f, 0, sizeof f);
	for (int i = 0; i <= tt; i++) {
		if (v[i] == 0) {
			f[0][i] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i < IchLiebeDich::L; i++) {
		for (int j = 0; j <= tt; j++) {
			for (int d = 0; d < 10; d++) {
//				if (i == 1 && j == 0 && k == 0) {
//					printf("%d %d %d %d\n", d, t[j][d], max(k, v[t[j][d]]), f[i - 1][t[j][d]][max(k, v[t[j][d]])]);
//				}
				if (v[j] || v[t[j][d]]) {
					continue;
				}
				f[i][j] += f[i - 1][t[j][d]];
				cnt++;
			}
		}
	}
	long long L = 0;
	long long R = 2000000000000000000LL;
	while (L < R - 1) {
		long long M = (L + R) /  2;
		if (solve(M) < 500000) {
			L = M;
		} else {
			R = M;
		}
	}
	printf("%lld\n", R);
	return 0;
}
