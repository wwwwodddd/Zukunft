#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n, x, z;
int main() {
	s.insert(-1000000000);
	s.insert(1000000000);
	cin >> n;
	cin >> x;
	z = x;
	s.insert(x);
	for (int i = 1; i < n; i++) {
		cin >> x;
		set<int>::iterator it;
		it = s.lower_bound(x);
		set<int>::iterator ti=it;
		ti--;
		z += min(*it - x, x - *ti);
		s.insert(x);
	}
	cout << z << endl;
	return 0;
}