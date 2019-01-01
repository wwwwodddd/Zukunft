#include <bits/stdc++.h>
using namespace std;
int n, s, t, x, y;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		s += x + y - 8;
		t += s;
	}
	printf("%d\n", t);
	return 0;
}
