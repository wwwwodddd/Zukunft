#include <bits/stdc++.h>
using namespace std;
string n;
int s;
int main()
{
	cin >> n;
	for (char i: n)
	{
		s += i - '0';
	}
	cout << (s % 9 ? "No" : "Yes") << endl;
	return 0;
}
