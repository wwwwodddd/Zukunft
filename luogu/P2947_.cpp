#include <bits/stdc++.h>
using namespace std;
int n;
int h[100020];
int s[100020], ss;
int z[100020];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = n; i > 0; i--) {
		while (ss > 0 && h[i] >= h[s[ss]]) {
			ss--;
		}
		z[i] = s[ss];
		s[++ss] = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", z[i]);
	}
	return 0;
}