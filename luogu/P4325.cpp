#include <bits/stdc++.h>
using namespace std;
int v[42], x, z;
int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &x);
		z += !v[x % 42]++;
	}
	printf("%d\n", z);
	return 0;
}