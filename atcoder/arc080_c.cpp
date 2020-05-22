#include <bits/stdc++.h>
using namespace std;
struct N {
	int v, l, x, y, r;
};
bool operator<(const N &a, const N &b) {
	return a.v > b.v;
}
priority_queue<N> q;
int n, a[200020];
pair<int, int> f[400020][18];
pair<int, int> Q(int x, int y) {
	int l = 31 - __builtin_clz(y - x);
	return min(f[x][l], f[y - (1 << l)][l]);
}
void push(int l, int r) {
	if (l == r) {
		return;
	}
	pair<int, int> x = Q(l, r);
	pair<int, int> y = Q(x.second + 1, r + 1);
	q.push({x.first, l, x.second, y.second, r});
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		f[i][1] = make_pair(a[i], i);
	}
	for (int j = 1; j < 17; j++) {
		for (int i = 0; i < n; i++) {
			f[i][j + 1] = min(f[i][j], f[i + (1 << j)][j]);
		}
	}
	push(0, n);
	while (q.size()) {
		N u = q.top();
		q.pop();
		printf("%d %d ", a[u.x], a[u.y]);
		push(u.l, u.x);
		push(u.x + 1, u.y);
		push(u.y + 1, u.r);
	}
	return 0;
}
