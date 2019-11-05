#include <iostream>
#include <cstdio>
using namespace std;
int c[10];
long long ans;
void dfs(int sum, int x, int y) {
	if (x == 10) {
		if (y == 10 && (90 - sum - sum) % 11 == 0) {
	//		(你说的对！)
			long long tmp = 1;
			for (int i = 1; i <= 10; i++) {
				tmp *= i;
			}
			for (int i = 1; i <= 10; i++) {
				tmp *= i;
			}
			for (int i = 0; i < 10; i++) {
				if (c[i] == 1) {

				} else {
					tmp /= 2;
				}
			}
			if (c[0] == 2) {
				tmp = tmp / 10 * 8;
			} else if (c[0] == 1) {
				tmp = tmp / 10 * 9;
			}
			ans += tmp;
		}
		return;
	}
	for (c[x] = 0; c[x] <= 2; c[x]++) {
		dfs(sum + c[x] * x, x + 1, y + c[x]);
	}
}
int main() {
	dfs(0, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
