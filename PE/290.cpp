#include <bits/stdc++.h>
using namespace std;
long long f[20][400][140];
int main() {
	f[0][200][0] = 1;
	for (int i = 0; i < 18; i++) {
		for (int j = 10; j < 390; j++) {
			for (int k = 0; k < 140; k++) {
				for (int l = 0; l < 10; l++) {
					f[i + 1][j + l - (l * 137 + k) % 10][(l * 137 + k) / 10] += f[i][j][k];
				}
			}
		}
	}
	long long ans = 0;
	for (int k = 0; k < 140; k++) {
		ans += f[18][200 + k % 10 + k / 10 % 10 + k / 100 % 10][k];
	}
	cout << ans << endl;
	return 0;
}