#include <bits/stdc++.h>
using namespace std;
bool Prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int z[100000], zc;
int main() {
	for (int i = 1; i <= 10000; i++) {
		{
			char s[20] = {};
			sprintf(s, "%d", i);
			int l = strlen(s);
			for (int i = 0; i < l; i++) {
				s[2 * l - 2 - i] = s[i];
			}
			int x;
			sscanf(s, "%d", &x);
			if (Prime(x)) {
				z[zc++] = x;
			}
		}
		{
			char s[20] = {};
			sprintf(s, "%d", i);
			int l = strlen(s);
			for (int i = 0; i < l; i++) {
				s[2 * l - 1 - i] = s[i];
			}
			int x;
			sscanf(s, "%d", &x);
			if (Prime(x)) {
				z[zc++] = x;
			}
		}
	}
	sort(z, z + zc);
	int l, r;
	scanf("%d%d", &l, &r);
	for (int i = 0; i < zc; i++) {
		if (l <= z[i] && z[i] <= r) {
			printf("%d\n", z[i]);
		}
	}
	return 0;
}