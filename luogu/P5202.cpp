#include <bits/stdc++.h>
using namespace std;
int n, m, b, f;
int q[300020];
int g[300020];
int s[300020];
char c[300020];
int main() {
	scanf("%d%d%s", &n, &m, c);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + (c[i] == 'H' ? 1 : -1);
	}
	q[f++] = 0;
	for (int i = 1; i <= n; i++) {
		while (q[b] < i - m) {
			b++;
		}
		g[i] = g[q[b]] + (s[i] - s[q[b]] <= 0);
		while (b < f && make_pair(g[q[f - 1]], s[q[f - 1]]) >= make_pair(g[i], s[i])) {
			f--;
		}
		q[f++] = i;
	}
	printf("%d\n", g[n]);
	return 0;
}