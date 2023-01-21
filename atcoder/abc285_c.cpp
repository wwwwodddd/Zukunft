#include <bits/stdc++.h>
using namespace std;
string s;
long long z;
int main()
{
	cin >> s;
	for (char c : s)
	{
		z = z * 26 + c - 64;
	}
	cout << z << endl;
	return 0;
}