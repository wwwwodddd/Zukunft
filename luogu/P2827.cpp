#include <bits/stdc++.h>
using namespace std;
int n, m, q, u, v, t, x;
int q0[7000020], b0, f0;
int q1[7000020], b1, f1;
int q2[7000020], b2, f2;
int get() {
	int w = -2e9;
	if (b0 < f0) {
		w = max(w, q0[b0]);
	}
	if (b1 < f1) {
		w = max(w, q1[b1]);
	}
	if (b2 < f2) {
		w = max(w, q2[b2]);
	}
	if (b0 < f0 && w == q0[b0]) {
		b0++;
		return w;
	}
	if (b1 < f1 && w == q1[b1]) {
		b1++;
		return w;
	}
	if (b2 < f2 && w == q2[b2]) {
		b2++;
		return w;
	}
	printf("%d\n", w);
	assert(false);
}
int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		q0[f0++] = x;
	}
	sort(q0, q0 + f0, greater<int>());
	for (int i = 1; i <= m; i++) {
		int w = get() + (i - 1) * q;
		if (i % t == 0) {
			printf("%d ", w);
		}
		int w1 = (long long)w * u / v;
		int w2 = (w - w1);
		q1[f1++] = w1 - i * q;
		q2[f2++] = w2 - i * q;
	}
	printf("\n");
	for (int i = 1; i <= n + m; i++) {
		int u = get() + m * q;
		if (i % t == 0) {
			printf("%d ", u);
		}
	}
	printf("\n");
	return 0;
}