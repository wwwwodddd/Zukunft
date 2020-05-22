#include <bits/stdc++.h>
using namespace std;
int n, p[200020];
double z;
int main() {
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		z += p[i] / (n - 1.) * i;
	}
	printf("%.12f\n", z);
	return 0;
}