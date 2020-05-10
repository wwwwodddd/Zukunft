#include <bits/stdc++.h>
const int N = 200020;
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

	void add(int c) {
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
	}

	void count() {
		for (int i = p - 1; i >= 2; i--) {
			cnt[fail[i]] += cnt[i];
		}
	}
}A, B;

char a[N];
char b[N];
long long ans = 0;
void dfs(int x, int y) {
	if (x != 0 && y != 0) {
		ans += (long long)A.cnt[x] * B.cnt[y];
	} else {
		assert(x == 0 && y == 0);
	}
	for (int i = 0; i < 26; i++) {
		if (A.next[x][i] != 0 && B.next[y][i] != 0) {
			dfs(A.next[x][i], B.next[y][i]);
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		A.init();
		B.init();
		scanf("%s", a);
		scanf("%s", b);
		int la = strlen(a);
		int lb = strlen(b);
		for (int i = 0; i < la; i++) {
			A.add(a[i]);
		}
		for (int i = 0; i < lb; i++) {
			B.add(b[i]);
		}
		A.count();
		B.count();
		ans = 0;
		dfs(0, 0);
		dfs(1, 1);
		printf("Case #%d: %lld\n", tt, ans);
	}
	return 0;
}