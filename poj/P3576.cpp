#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int t[150020][26];
long long w[150020];
char s[40];
int n, tt = 1;
void ins(char *s) {
	int p = 1;
	for(; *s; s++) {
		if (t[p][*s - 'a'] == 0) {
			t[p][*s - 'a'] = ++tt;
		}
		p = t[p][*s - 'a'];
	}
	w[p] = 1;
}
void dfs(int x) {
	for (int i = 0; i < 26; i++) {
		if (t[x][i] > 0) {
			dfs(t[x][i]);
		}
		w[x] = w[x] * 10007 + w[t[x][i]] + 131;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		ins(s);
	}
	dfs(1);
	sort(w + 1, w + tt + 1);
	tt = unique(w + 1, w + tt + 1) - (w + 1);
	printf("%d\n", tt);
	return 0;
}