#include <bits/stdc++.h>
using namespace std;
char s[14];
int z, a[14] = {1, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9};
int main() {
	scanf("%s", s);
	for (int i = 0; i < 14; i++) {
		z += s[i] * a[i];
	}
	z += 7;
	z %= 11;
	if (z == 10) {
		z = 'X';
	} else {
		z += '0';
	}
	if (z == s[12]) {
		printf("Right\n");
	} else {
		s[12] = z;
		printf("%s\n", s);
	}
	return 0;
}
