#include <bits/stdc++.h>
using namespace std;
int n, a[220];
vector<int> z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		z.push_back(1);
		for (int j = 1; j < n; j++) {
			if (a[j - 1] > a[j]) {
				z.push_back(n - 1);
				swap(a[j - 1], a[j]);
			}
			z.push_back(1);
		}
	}
	printf("%d\n", z.size());
	for (int i: z) {
		printf("%d\n", i);
	}
	return 0;
}