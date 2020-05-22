#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	int z = s.size();
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			z = min(z, max(i, (int)s.size() - i));
		}
	}
	printf("%d\n", z);
	return 0;
}