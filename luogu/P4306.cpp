#include <bits/stdc++.h>
using namespace std;
bitset<2000>d[2000];
char s[2020];
int n, z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				d[i][j] = 1;
			}
		}
		d[i][i] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (d[i][k]) {
				d[i] |= d[k];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		z += d[i].count();
	}
	printf("%d\n", z);
}