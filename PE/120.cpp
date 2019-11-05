#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n = 1000, ans;
int F(int i) {
	int xx = 1;
	int yy = 1;
	int x = i - 1;
	int y = i + 1;
	int mx = 0;
	for (int j = 0; j < i * i; j++) {
		mx = max(mx, (xx + yy) % (i * i));
		xx = xx * x % (i * i);
		yy = yy * y % (i * i);
	}
	return mx;
}
int main() {
	printf("%d\n", F(7));
	for (int i = 3; i <= n; i++) {
		printf("%d\n", i);
		ans += F(i);
	}
	printf("%d\n", ans);
	return 0;
}