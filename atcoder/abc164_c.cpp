#include <bits/stdc++.h>
using namespace std;
set<string> t;
string s;
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		t.insert(s);
	}
	cout << t.size() << endl;
	return 0;
}
