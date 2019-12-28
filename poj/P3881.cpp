#include <stdio.h>
int s[10020], e[10020];
int n, m;
int main() {
	while(scanf("%d%d", &n ,&m), n + m) {
		for (int i = 0; i < n; i++) {
			scanf("%*d%*d%d%d", s + i, e + i);
			e[i] += s[i];
		}
		for (int i = 0; i < m; i++) {
			int l, r, c = 0;
			scanf("%d%d", &l, &r);
			r += l;
			for (int j = 0; j < n; j++) {
				if (l < e[j] && s[j] < r) {
					c++;
				}
			}
			printf("%d\n", c);
		}
	}
	return 0;
}