#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> a[100020];
int n;
int cmp(pair<int, int> a, pair<int, int> b) {
	return a.first + a.second < b.first + b.second;
}
int ok() {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s = max(s, a[i].first);
		s += (a[i].second - a[i].first + 2) / 2;
		if (s > a[i].second) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	for (; scanf("%d", &n), n;) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a, a + n, cmp);
		printf("%s\n", ok() ? "YES" : "NO");
	}
}