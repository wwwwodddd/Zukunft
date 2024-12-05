#include <bits/stdc++.h>
using namespace std;
const int p = 10007;
int n;
string s;
vector<pair<int, int>> a;
vector<char> b;
pair<int, int> jia(pair<int, int> u, pair<int, int> v)
{
	return make_pair((u.first * v.first) % p, (u.first * v.second + u.second * v.first + u.second * v.second) % p);
}
pair<int, int> cheng(pair<int, int> u, pair<int, int> v)
{
	return make_pair((u.first * v.first + u.first * v.second + u.second * v.first) % p, (u.second * v.second) % p);
}
int pre(char o)
{
	if (o == '*')
	{
		return 2;
	}
	else if (o == '+')
	{
		return 1;
	}
	else if (o == ')')
	{
		return -1;
	}
	else if (o == '(')
	{
		return -2;
	}
	return 0;
}
int main()
{
	cin >> n >> s;
	s = "(" + s + ")";
	for (int i = 0; i < s.size(); i++)
	{
		if (i > 0 && s[i - 1] != ')' && s[i] != '(')
		{
			a.push_back(make_pair(1, 1));
		}
		if (s[i] == '(')
		{
			b.push_back(s[i]);
		}
		else
		{
			while (pre(s[i]) <= pre(b.back()))
			{
				pair<int, int> v = a.back();
				a.pop_back();
				pair<int, int> u = a.back();
				a.pop_back();
				if (b.back() == '+')
				{
					a.push_back(jia(u, v));
				}
				else if (b.back() == '*')
				{
					a.push_back(cheng(u, v));
				}
				b.pop_back();
			}
			if (s[i] == ')')
			{
				b.pop_back();
			}
			else
			{
				b.push_back(s[i]);
			}
		}
	}
	cout << a[0].first << endl;
	return 0;
}