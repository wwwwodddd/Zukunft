#include <bits/stdc++.h>
using namespace std;
string s, z;
deque<char> q;
int f;
int main()
{
	cin >> s;
	for (char i : s)
	{
		if (i == 'R')
		{
			f ^= 1;
		}
		else
		{
			if (f)
			{
				q.push_front(i);
			}
			else
			{
				q.push_back(i);
			}
		}
	}
	if (f)
	{
		reverse(q.begin(), q.end());
	}
	for (char i : q)
	{
		if (z.size() && z.back() == i)
		{
			z.pop_back();
		}
		else
		{
			z.push_back(i);
		}
	}
	cout << z << endl;
	return 0;
}