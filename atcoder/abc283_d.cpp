#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> t;
int b;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			t.push_back(b);
		}
		else if (s[i] == ')')
		{
			b = t.back();
			t.pop_back();
		}
		else
		{
			int d = 1 << s[i] - 'a';
			if (b & d)
			{
				cout << "No" << endl;
				return 0;
			}
			b |= d;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
