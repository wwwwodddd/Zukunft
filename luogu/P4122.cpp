#include <bits/stdc++.h>
using namespace std;
struct rec {
	int l, d, r, u;
	void scan() {
		scanf("%d%d%d%d", &l, &d, &r, &u);
	}
	int area() {
		return max(0, u - d) * max(0, r - l);
	}
} a, b, c;
rec intersect(rec A, rec B) {
	return {max(A.l, B.l), max(A.d, B.d), min(A.r, B.r), min(A.u, B.u)};
}
int main() {
	a.scan();
	b.scan();
	c.scan();
	printf("%d\n", a.area() + b.area() - intersect(a, c).area() - intersect(b, c).area());
	return 0;
}