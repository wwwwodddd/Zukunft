#include <iostream>
#include <cstdio>
using namespace std;
int f[240][240];
// yong 3 ge shu, dou dayu dengyu x, he wei 15 fanganshu.
void calc(int x) {
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 9; j >= 0; j--) {
			for (int k = 100; k >= 0; k--) {
				for (int l = x + 1; l <= 12; l++) {
					f[j][k + l] += f[j][k];
				}
				f[j + 1][k + x] += f[j][k];
				f[j][k] = 0;
			}
		}
	}
}
long long C(int n, int m) {
	long long re = 1;
	for (int i = 0; i < m; i++) {
		re = re * (n - i) / (i + 1);
	}
	return re;
}
long long pw(int x, int y) {
	long long re = 1;
	for (int i = 0; i < y; i++) {
		re *= x;
	}
	return re;
}
int main() {
	long long ans = 0;
	for (int i = 1; i <= 12; i++) {
		calc(i);
		for (int j = 0; j <= 20; j++) {
			for (int k = 1; k <= j && k <= 10; k++) { // k ge i zai top3 yigong j ge i, 
				if (j - k <= 10) {
					long long tmp = pw(i - 1, 10 - (j - k)) * C(20, 10 - (j - k)) * f[k][70] / C(10, k) * C(10 + (j - k), j);
					ans += tmp;
					if (tmp > 0) {
						printf("%d %d %d\n", j, k, tmp);
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/*

#include <iostream>
#include <cstdio>
using namespace std;
int f[120][120];
// yong 3 ge shu, dou dayu dengyu x, he wei 15 fanganshu.
void calc(int x) {
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 2; j >= 0; j--) {
			for (int k = 100; k >= 0; k--) {
				for (int l = x + 1; l <= 6; l++) {
					f[j][k + l] += f[j][k];
				}
				f[j + 1][k + x] += f[j][k];
				f[j][k] = 0;
			}
		}
	}
}
int C(int n, int m) {
	int re = 1;
	for (int i = 0; i < m; i++) {
		re = re * (n - i) / (i + 1);
	}
	return re;
}
int pw(int x, int y) {
	int re = 1;
	for (int i = 0; i < y; i++) {
		re *= x;
	}
	return re;
}
int main() {
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		calc(i);
		for (int j = 0; j <= 5; j++) {
			for (int k = 1; k <= j && k <= 3; k++) { // k ge i zai top3 yigong j ge i, 
				if (j - k <= 2) {
					int tmp = pw(i - 1, 2 - (j - k)) * C(5, 2 - (j - k)) * f[k][15] / C(3, k) * C(3 + (j - k), j);
					ans += tmp;
					printf("%d %d %d\n", j, k, tmp);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
*/

