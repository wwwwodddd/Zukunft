#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
void pushb()
{
	if (t.size() > 0 && t.back() == 'B')
	{
		t.pop_back();
		t.push_back('A');
	}
	else
	{
		t.push_back('B');
	}
}
int main()
{
	cin >> n >> s;
	for (char i: s)
	{
		if (i == 'C')
		{
			t += 'C';
		}
		else
		{
			pushb();
			if (i == 'A')
			{
				pushb();
			}
		}
	}
	cout << t << endl;
	return 0;
}
