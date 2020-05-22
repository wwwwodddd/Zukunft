#include <bits/stdc++.h>
using namespace std;
int n, x, c[4];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		c[x % 4]++;
	}
	c[1] += c[3];
	printf("%s\n", c[0] >= c[1] || c[2] == 0 && c[0] >= c[1] - 1 ? "Yes" : "No");
	return 0;
}