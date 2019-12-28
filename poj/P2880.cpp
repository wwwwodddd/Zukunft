#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int t[4020][2], tt, w[4020], no;
string s[50];
char cao[10020];
void ins(string s) {
	int p = 1;
	for (int i = 0; i < s.size(); i++) {
		if (t[p][s[i] - '0'] == 0) {
			t[p][s[i] - '0'] = ++tt;
		}
		p = t[p][s[i] - '0'];
	}
	return;
}
void dfs(int x) {
	int c = 0;
	for (int i = 0; i < 2; i++) {
		if (t[x][i]) {
			dfs(t[x][i]);
			c++;
		}
	}
	if (c == 0) {
		w[x] = 2;
	} else if (c == 1) {
		w[x] = 1;
	} else {
		w[x] = min(w[t[x][0]], w[t[x][1]]) + 1;
	}
}
int main() {
	for (scanf("%d ", &no); no--;) {
		tt = 1;
		memset(t, 0, sizeof t);
		memset(w, 0, sizeof w);
		int n = 0;
		gets(cao);
		istringstream in(cao);
		while (in >> s[n]) {
			n++;
		}
		n--;
		for (int i = 0; i < n; i++) {
			ins(s[i]);
		}
		dfs(1);
		int p = 1, i;
		int ans = 0xffff;
		for (i = 0; i < s[n].size(); i++) {
			if (t[p][s[n][i] - '0']) {
				p = t[p][s[n][i] - '0'];
			} else {
				if (t[p][0] == 0 && t[p][1] == 0) {
					ans = 1;
				} else {
					ans = 0;
				}
				break;
			}
		}
		if (i == s[n].size()) {
			ans = w[p];
		}
		printf("%d\n", ans);
	}
	return 0;
}