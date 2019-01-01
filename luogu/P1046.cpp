#include <bits/stdc++.h>
using namespace std;
int a[10], x, c;
int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	for (int i = 0; i < 10; i++) {
		if (x + 30 >= a[i]) {
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}
