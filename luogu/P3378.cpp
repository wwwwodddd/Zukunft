#include <bits/stdc++.h>
using namespace std;
int n, a[1000020];
void up(int x) {
	while (x > 1) {
		if (a[x] < a[x / 2]) {
			swap(a[x], a[x / 2]);
			x /= 2;
		} else {
			break;
		}
	}
}
void down(int x) {
	while (2 * x <= n) {
		int p = 2 * x;
		if (p + 1 <= n && a[p + 1] < a[p]) {
			p++;
		}
		if (a[x] > a[p]) {
			swap(a[x], a[p]);
			x = p;
		} else {
			break;
		}
	}
}
int top() {
	// n >= 1
	return a[1];
}
void push(int x) {
	n++;
	a[n] = x;
	up(n);
}
void pop() {
	swap(a[1], a[n]);
	n--;
	down(1);
}
int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d", &x);
		if (x == 1) {
			scanf("%d", &y);
			push(y);
		} else if (x == 2) {
			printf("%d\n", top());
		} else {
			pop();
		}
	}
}