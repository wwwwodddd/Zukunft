#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	scanf("%d", &n);
	double s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			x++;
		} else {
			x *= 2;
		}
		s += 2.0 / (x);
	}
	printf("%.12f\n", s);
	return 0;
}