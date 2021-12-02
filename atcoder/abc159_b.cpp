#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != s[n - 1 - i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	if (s.substr(0, n / 2) != s.substr(n - n / 2))
	{
		cout << "No" << endl;
	}
	else
	{	
		cout << "Yes" << endl;
	}
	return 0;
}



dang
