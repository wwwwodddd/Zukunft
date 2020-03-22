#include <bits/stdc++.h>
using namespace std;
int cnt;
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j - 1] && a[i - 1] == b[j]) {
				cnt++;
			}
		}
	}
	cout << (1 << cnt) << endl;
}