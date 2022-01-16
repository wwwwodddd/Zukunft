#include <bits/stdc++.h>
using namespace std;
string s;
set<string> t;
int k;
int main()
{
	cin >> s >> k;
	for (int i = 0; i + k <= s.size(); i++)
	{
		t.insert(s.substr(i, k));
	}
	cout << t.size() << endl;
	return 0;
}
