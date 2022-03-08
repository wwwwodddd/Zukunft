#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > s;
int n, x, c;
int main()
{
	cin >> n;
	s.push(make_pair(0, 0));
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x == s.top().first)
		{
			s.top().second++;
			if (s.top().first == s.top().second)
			{
				c += s.top().second;
				s.pop();
			}
		}
		else
		{
			s.push(make_pair(x, 1));
		}
		cout << i - c << endl;
	}
	return 0;
}