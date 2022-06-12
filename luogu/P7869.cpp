#include <bits/stdc++.h>
using namespace std;
string s;
string z[4] = {"", "linux", "mac", "windows"};
int f;
int main()
{
	getline(cin, s);
	if (s.find("\\n") != -1)
	{
		f += 1;
	}
	if (s.find("\\r") != -1)
	{
		f += 2;
	}
	cout << z[f] << endl;
	return 0;
}
