#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int n, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		g[x]++;
	}
	for (map<int, int>::iterator i = g.begin(); i != g.end(); i++) {
		printf("%d %d\n", i->first, i->second);
	}
	return 0;
}