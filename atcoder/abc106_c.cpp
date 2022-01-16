#include <bits/stdc++.h>
using namespace std;
string s;
long long k;
int main()
{
	cin >> s >> k;
	k--;
	s += '6';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '1')
		{
			if (k < i)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << s[i] << endl;
			}
			break;
		}
	}
	return 0;
}
