#include <bits/stdc++.h>

int v[1000020];
int s[1000020];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= m; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= m; j += i) {
			v[j] = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		s[i] = s[i - 1];
		if (v[i] == i) {
			s[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l < 1 || r > m) {
			printf("Crossing the line\n");
		} else {
			printf("%d\n", s[r] - s[l - 1]);
		}
	}
	return 0;
}