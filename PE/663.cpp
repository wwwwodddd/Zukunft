#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node{
	long long sm, lm, rm, mx;
	Node(long long sm=0, long long lm=0, long long rm=0, long long mx=0): sm(sm), lm(lm), rm(rm), mx(mx) {
	}
}t[33554433];
int a[33554432];
int b[33554432];
Node operator+(const Node&a, const Node&b) {
	return Node(a.sm+b.sm, max(a.lm, a.sm+b.lm), max(a.rm+b.sm, b.rm), max(a.rm+b.lm, max(a.mx, b.mx)));
}
void build(int x, int l, int r) {
	if (l + 1 == r) {
		t[x] = Node(a[l], a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2 + 1, l, mid);
	build(x * 2 + 2, mid, r);
	t[x] = t[x * 2 + 1] + t[x * 2 + 2];
}
void change(int x, int l, int r, int p, int v) {
	if (l + 1 == r) {
		a[l] += v;
		t[x] = Node(a[l], a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) / 2;
	if (p < mid) {
		change(2 * x + 1, l, mid, p, v);
	} else {
		change(2 * x + 2, mid, r, p, v);
	}
	t[x] = t[x * 2 + 1] + t[x * 2 + 2];
}
long long S(int n, int l1, int l2) {
	b[2] = 1;
	for (int i = 3; i < 33554432; i++) {
		b[i] = (b[i - 1] + b[i - 2] + b[i - 3]) % n;
	}
	for (int i = 1; i <= l1; i++) {
		a[b[2 * i - 2]] += 2 * b[2 * i - 1] - n + 1;
	}
	build(0, 0, n);
	long long ans = 0;
	for (int i = l1 + 1; i <= l2; i++) {
		change(0, 0, n, b[2 * i - 2], 2 * b[2 * i - 1] - n + 1);
		ans += t[0].mx;
//		cerr << t[0].mx << endl;
	}
	return ans;
}
int main() {
	long long ans = S(10000003, 10000000, 10200000);
	cout << ans << endl;
	return 0;
}