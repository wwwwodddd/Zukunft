#include <bits/stdc++.h>
using namespace std;
int a, b;
string s;
int main()
{
	cin >> a >> b >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' ^ i == a)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;	
}
