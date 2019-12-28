#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char s[10020];
char z[10020];
int l[10020];
int r[10020];
int q[10020];
int t, n, p, b, f;
int dfs() {
	int cur = p;
	p--;
	if ('A' <= s[cur] && s[cur] <= 'Z') {
		r[cur] = dfs();
		l[cur] = dfs();
	}
	return cur;
}
int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%s", s + 1);	
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		b = f = 0;
		p = n = strlen(s + 1);
		dfs();
		q[f++] = n;
		while (b < f) {
			if (l[q[b]]) {
				q[f++] = l[q[b]];
			}
			if (r[q[b]]) {
				q[f++] = r[q[b]];
			}
			b++;
		}
		for (int i = f; i-- > 0;) {
			z[f - 1 - i] = s[q[i]];
		}
		z[f] = 0;
		puts(z);
	}
}
