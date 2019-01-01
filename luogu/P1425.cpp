#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int e = (c - a) * 60 + (d - b);
	printf("%d %d\n", e / 60, e % 60);
	return 0;
}
