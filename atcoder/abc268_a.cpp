#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
set<int> s;
int main()
{
	cin >> a >> b >> c >> d >> e;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	s.insert(d);
	s.insert(e);
	cout << s.size() << endl;
	return 0;
}