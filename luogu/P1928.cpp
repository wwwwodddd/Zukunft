#include <bits/stdc++.h>
using namespace std;
string read()
{
	string s;
	for (char c; cin >> c;)
	{
		if (c == '[')
		{
			int d;
			cin >> d;
			string t = read();
			for (int i = 0; i < d; i++)
			{
				s += t;
			}
		}
		else if (c == ']')
		{
			break;
		}
		else
		{
			s += c;
		}
	}
	return s;
}
int main()
{
	cout << read() << endl;
	return 0;
}