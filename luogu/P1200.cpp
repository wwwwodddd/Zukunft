#include <bits/stdc++.h>
using namespace std;
char a[10];
char b[10];
int main() {
	cin >> a >> b;
	int la = strlen(a), sa = 1;
	int lb = strlen(b), sb = 1;
	for (int i = 0; i < la; i++) {
		sa *= a[i] - 'A' + 1;
		sa %= 47;
	}
	for (int i = 0; i < lb; i++) {
		sb *= b[i] - 'A' + 1;
		sb %= 47;
	}
	printf(sa == sb ? "GO\n" : "STAY\n");
	return 0;
}
