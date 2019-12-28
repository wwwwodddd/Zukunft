#include <cstdio>
using namespace std;
int n, a[100], first;
int main() {
	while (scanf("%d", &n), n) {
		if (first) {
			printf("\n");
		}
		first = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			int tmp = 0, l = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] >= a[i]) {
					tmp += a[j] - a[i];
				}
			}
			for (int j = 0; j < 2 * n; j++) {
				if (a[j % n] >= a[i]) {
					if (j - l >= (n + 1) / 2) {
						goto end;
					}
					l = j;
				}
			}
			if (ans > tmp) {
				ans = tmp;
			}
			end:;
		}
		printf("%d\n", ans);
	}
	return 0;
}