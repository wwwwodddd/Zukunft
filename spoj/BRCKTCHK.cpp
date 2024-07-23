#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> a;
bool ok()
{
	for (char i : s)
	{
		if (i == ')')
		{
			if (a.size() > 0 && a.back() == '(')
			{
				a.pop_back();
			}
			else
			{
				return false;
			}
		}
		else if (i == ']')
		{
			if (a.size() > 0 && a.back() == '[')
			{
				a.pop_back();
			}
			else
			{
				return false;
			}
		}
		else if (i == '}')
		{
			if (a.size() > 0 && a.back() == '{')
			{
				a.pop_back();
			}
			else
			{
				return false;
			}
		}
		else if (i == '>')
		{
			if (a.size() > 0 && a.back() == '<')
			{
				a.pop_back();
			}
			else
			{
				return false;
			}
		}
		else
		{
			a.push_back(i);
		}
	}
	return a.size() == 0;
}
int main()
{
	cin >> s;
	cout << (ok() ? "Yes" : "No") << endl;
	return 0;
}