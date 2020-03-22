#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		int s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			s ^= x;
		} 
		printf(s ? "Yes\n" : "No\n");
	}
}