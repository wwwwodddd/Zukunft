#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
void up(int x) {
	while (x > 1) {
		if (a[x] > a[x / 2]) {
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
		if (p + 1 <= n && a[p + 1] > a[p]) {
			p++;
		}
		if (a[x] < a[p]) {
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
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
	}
	n = m;
	for (int i = m / 2; i > 0; i--) {
		down(i);
	}
	for (int i = m; i > 0; i--) {
		pop();
	}
	for (int i = 1; i <= m; i++) {
		printf("%d%c", a[i], i == m ? '\n' : ' ');
	}
}