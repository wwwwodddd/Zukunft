#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[100020];
int r[100020];
int cmp(int x, int y) {
	return a[x] < a[y];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		r[i] = i;
	}
//	stable_sort(r, r + n, [](int x, int y){return a[x] < a[y];});
	stable_sort(r, r + n, cmp);
	for (int i = 0; i < n; i++) {
		z = max(z, r[i] - i);
	}
	printf("%d\n", z + 1);
	return 0;
}