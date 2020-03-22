#include <bits/stdc++.h>
using namespace std;
string s;
long long z, c;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'z') {
			c++;
		} else if (s[i] == 'y'){
			z += c * (c - 1) / 2;
		}
	}
	cout << z << endl;
	return 0;
}