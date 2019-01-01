#include <bits/stdc++.h>
using namespace std;
int n;
int a[3020], b[3020];
void swap() { // jiaohuan a he b
	for (int i = 0; i < 3010; i++) {
		swap(a[i], b[i]);
	}
}
void add() { // a += b
	for (int i = 0; i < 3010; i++) {
		a[i] += b[i];
	}
	for (int i = 0; i < 3010; i++) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
}

int main() {
	a[0] = 1;
	b[0] = 1;
	scanf("%d", &n);
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) { // a, b   -> b, a + b
		add();
		swap();
	}
	int l = 3010;
	while (a[l] == 0) {
		l--;
	}
	for (int i = l; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}