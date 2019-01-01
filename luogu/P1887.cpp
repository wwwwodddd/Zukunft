#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = m; i > 0; i--) {
		if (i > n % m) {
			printf("%d", n / m);
		} else {
			printf("%d", n / m + 1);
		}
		printf("%c", i == 1 ? '\n' : ' ');
	}
	return 0;
}