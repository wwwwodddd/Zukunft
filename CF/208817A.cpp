#include <bits/stdc++.h>
using namespace std;
char s[200020];
int main() {
	scanf("%s", s);
	int n = strlen(s);
	reverse(s, s + n);
	for (int i = 0; i < n; i++) {
		s[i] -= '0';
	}
	bool st = false;
	for (int i = 200000; i >= 0; i -= 4) {
		int v = (s[i + 3] << 9) + (s[i + 2] << 6) + (s[i + 1] << 3) + s[i + 0];
		if (st) {
			printf("%03X", v);
		} else {
			if (v || i == 0) {
				printf("%X", v);
				st = true;
			}
		}
	}
	printf("\n");
	return 0;
}