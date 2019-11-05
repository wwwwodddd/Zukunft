#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long long f[10][10][50][10];
int main() {
	for (int i = 1; i < 10; i++) {
		f[i][i][1][i] = 1;
	}
	for (int i = 1; i < 40; i++) {
		for (int low = 0; low < 10; low++) {
			for (int high = low; high < 10; high++) {
				for (int j = 0; j < 10; j++) {
					if (j + 1 < 10) {
						f[low][max(high, j + 1)][i + 1][j + 1] += f[low][high][i][j];						
					} 
					if (j > 0) {
						f[min(low, j - 1)][high][i + 1][j - 1] += f[low][high][i][j];						
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 40; i++) {
		for (int j = 0; j < 10; j++) {
			ans += f[0][9][i][j];
		}
	}
///	printf("%d\n", f[0][9][10][0]);
	printf("%lld\n", ans);
	return 0;
}