#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, c = 0;
	string s;
	cin >> n >> s;
	sort(s.begin(), s.end());
	do
	{
		c++;
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));
	cout << c << endl;
}