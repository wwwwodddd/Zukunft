#include <bits/stdc++.h>
using namespace std;
int main() {
	int n = 47;
	int m = 43;
//	n = 3;
//	m = 2;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int x = i; x <= n; x++) {
				for (int y = j; y <= m; y++) {
					ans += (long long)(x - i + 1) * (y - j + 1);
				}
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			{
				int w = (i + 1) / 2 + (j + 1) / 2;
				int h = (i + j + 1) / 2;
				for (int x = w; x <= n; x++) {
					for (int y = h; y <= m; y++) {
						ans += (long long)(x - w + 1) * (y - h + 1);
					}
				}
			}
			{
				int w = i / 2 + j / 2 + 1;
				int h = (i + j) / 2 + 1;
				for (int x = w; x <= n; x++) {
					for (int y = h; y <= m; y++) {
						ans += (long long)(x - w + 1) * (y - h + 1);
					}
				}
			}
		}
	}
	cout << ans << endl;
}