#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int a[400020];
int mx[400020];
int v[1000020];
int t, n, m, o, x, y;
void bd(int x, int l, int r) {
	if (l + 1 == r) {
		scanf("%d", &a[x]);
		mx[x] = v[a[x]];
		return;
	}
	int m = (l + r) / 2;
	bd(x * 2, l, m);
	bd(x * 2 + 1, m, r);
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
void cg(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R && mx[x] == 1) {
		return;
	}
	if (r <= L || R <= l) {
		return;
	}
	if (l + 1 == r) {
		a[x] /= v[a[x]];
		mx[x] = v[a[x]];
		return;
	}
	int m = (l + r) / 2;
	cg(x * 2, l, m, L, R);
	cg(x * 2 + 1, m, r, L, R);
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
int qy(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return mx[x];
	}
	if (r <= L || R <= l) {
		return 1;
	}
	int m = (l + r) / 2;
	return max(qy(x * 2, l, m, L, R), qy(x * 2 + 1, m, r, L, R));
}

int main() {
	v[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= 1000000; j += i) {
			if (v[j] == 0) {
				v[j] = i;
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		bd(1, 0, n);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &o, &x, &y);
			x -= 1;
			if (o == 1) {
				printf("%d ", qy(1, 0, n, x, y));
			} else {
				cg(1, 0, n, x, y);
			}
		}
		printf("\n");
	}
	return 0;
}