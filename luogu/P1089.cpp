#include <bits/stdc++.h>
using namespace std;
int s, x, z;
int main() {
	for (int i = 0; i < 12; i++) {
		scanf("%d", &x);
		s += 300 - x;
		if (s < 0) {
			printf("%d\n", -i - 1);
			return 0;
		}
		z += s / 100;
		s %= 100;
	}
	printf("%d\n", z * 120 + s);
	return 0;
}
