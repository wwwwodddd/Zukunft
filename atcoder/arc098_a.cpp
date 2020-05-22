#include <bits/stdc++.h>
using namespace std;
int n, a, b, z;
char s[300020];
int main() {
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'E') {
			b++;
		}
	}
	z = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'E') {
			b--;
		}
		z = min(z, a + b);
		if (s[i] == 'W') {
			a++;
		}
	}
	printf("%d\n", z);
	return 0;
}