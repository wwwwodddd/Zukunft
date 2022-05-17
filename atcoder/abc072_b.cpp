#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i += 2)
	{
		cout << s[i];
	}
	cout << endl;
	return 0;
}
