#include <bits/stdc++.h>
using namespace std;
int a[3];
string s;
int main() {
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cin >> s;
	for (int i = 0; i < 3; i++) {
		printf("%d%c", a[s[i] - 'A'], i == 2 ? '\n' : ' ');
	}
	return 0;
}
