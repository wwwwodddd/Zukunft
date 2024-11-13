#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<string> s;
	string t;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.insert(t);
	}
	cout << 52 - s.size() << endl;
	return 0;
}