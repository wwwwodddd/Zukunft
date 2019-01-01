#include <bits/stdc++.h>
using namespace std;
void print(int n) {
	if (n == 0) {
		printf("0");
		return;
	}
	bool first = true;
	for (int i = 30; i >= 0; i--) {
		if (n >> i & 1) {
			if (!first) {
				printf("+");
			}
			first = false;
			if (i == 1) {
				printf("2");
			} else {
				printf("2(");
				print(i);
				printf(")");
			}
		}
	}
}
int n;
int main() {
	cin >> n;
	print(n);
	printf("\n");
	return 0;
}