#include <bits/stdc++.h>
using namespace std;
int n, z;
char s[320][320];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		int b = 1;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (s[(j + i) % n][k] != s[(k + i) % n][j]) {
					b = 0;
				}
			}
		}
		z += b;
	}
	printf("%d\n", z * n);
	return 0;
}