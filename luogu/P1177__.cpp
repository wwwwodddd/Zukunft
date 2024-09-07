#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int b[100020];
void merge_sort(int l, int r) {
	if (r - l <= 1) {
		return;
	}
	int m = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	int i = l, j = m, k = l;
	while (i < m || j < r) {
		if (j == r || i < m && a[i] < a[j]) {
			b[k++] = a[i++];	
		} else {
			b[k++] = a[j++];
		}
	}
	for (int i = l; i < r; i++) {
		a[i] = b[i];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	merge_sort(0, n);
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}