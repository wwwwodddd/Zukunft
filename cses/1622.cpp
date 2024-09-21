#include <bits/stdc++.h>
using namespace std;
string s;
int c;
int main()
{
	cin >> s;
	sort(s.begin(), s.end());
	do
	{
		c++;
	} while (next_permutation(s.begin(), s.end()));
	cout << c << endl;
	do
	{
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}