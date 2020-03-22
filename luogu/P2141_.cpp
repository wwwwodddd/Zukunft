#include <bits/stdc++.h>
using namespace std;
set<int> s;
int a[100];
int n, ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			s.insert(a[i] + a[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (s.find(a[i]) != s.end()) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
