#include <bits/stdc++.h>
using namespace std;
long long cnt;
int D = 24;
bool in(long long x, long long y) {
	x -= 1 << (D - 1);
	y -= 1 << (D - 1);
	long long xx = x * x;
	long long yy = y * y;
//	printf("%lld %lld %d\n", xx + yy, (1LL << (2 * D - 2)), (int)(xx + yy <= (1LL << (2 * D - 2))));
	return xx + yy <= (1LL << (2 * D - 2));
}
bool judge(int x, int y, int d) {
	if (d == D) {
		return false;
	}
//	printf("---\n");
	if (in(x, y) && in(x + (1 << d) - 1, y) && in(x, y + (1 << d) - 1) && in(x + (1 << d) - 1, y + (1 << d) - 1)) {
		return true;
	}
//	printf("---\n");
	if (!in(x, y) && !in(x + (1 << d) - 1, y) && !in(x, y + (1 << d) - 1) && !in(x + (1 << d) - 1, y + (1 << d) - 1)) {
		return true;
	}
	return false;
}
void F(int x, int y, int d) {
	cnt++;
	if (judge(x, y, d)) {
//		printf("%d %d %d\n", x, y, d);
//		printf("=.= %d %d\n", x - (1 << (D - 1)), y - (1 << (D - 1)));
		cnt++;
		return;
	}
	F(x, y + (1 << (d - 1)), d - 1);
	F(x + (1 << (d - 1)), y + (1 << (d - 1)), d - 1);
	F(x, y, d - 1);
	F(x + (1 << (d - 1)), y, d - 1);
}
int main() {
	F(0, 0, 24);
	cout << cnt << endl;
	return 0;
}