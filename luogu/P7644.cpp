#include <bits/stdc++.h>
using namespace std;
string s;
int a;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0 || s[i - 1] == '|')
		{
			if (s[i] == 'A' || s[i] == 'D' || s[i] == 'E')
			{
				a++;
			}
			else if (s[i] != 'B')
			{
				a--;
			}
		}
	}
	if (a == 0)
	{
		if (s[s.size() - 1] == 'A')
		{
			a++;
		}
		else
		{
			a--;
		}
	}
	cout << (a > 0 ? "A-mol" : "C-dur");
	return 0;
}
