#include <bits/stdc++.h>
const int N = 2000020;
struct Palindromic_Tree {
	int next[N][26];
	int fail[N];
	int cnt[N];
	int num[N];
	int len[N];
	int s[N];
	int last;
	int n;
	int p;
	Palindromic_Tree() {
		init();
	}

	int newnode(int l) {
		for (int i = 0; i < 26; i++) {
			next[p][i] = 0;
		}
		cnt[p] = 0;
		num[p] = 0;
		len[p] = l;
		return p++;
	}

	void init() {
		p = 0;
		newnode(0);
		newnode(-1);
		last = 0;
		n = 0;
		s[0] = -1;
		fail[0] = 1;
	}

	int getFail(int x) {
		while (s[n - len[x] - 1] != s[n]) {
			x = fail[x];
		}
		return x;
	}

	int add(int c) {
		c -= 'a';
		s[++n] = c;
		int cur = getFail(last);
		if (next[cur][c] == 0) {
			int now = newnode(len[cur] + 2);
			fail[now] = next[getFail(fail[cur])][c];
			next[cur][c] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = next[cur][c];
		cnt[last]++;
		return num[last];
	}

	void count() {
		for (int i = p - 1; i >= 2; i--) {
			cnt[fail[i]] += cnt[i];
		}
	}
}t;

int pre[N], suf[N];
int n, p = 51123987;
char s[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	t.init();
	for (int i = n - 1; i >= 0; i--) {
		pre[i] = t.add(s[i]);
	}
	t.count();
	long long z = 0;
	for (int i = 2; i < t.p; i++) {
		z += t.cnt[i];
		z %= p;
	}
	z = z * (z - 1) / 2 % p;
	t.init();
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		z = (z - sum * pre[i] % p + p) % p;
		sum += t.add(s[i]);
		sum %= p;
	}
	printf("%lld\n", z);
	return 0;
}