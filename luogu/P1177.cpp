#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}