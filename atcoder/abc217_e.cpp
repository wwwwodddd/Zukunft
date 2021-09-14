#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
queue<int> q;
int n, o, x;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> x;
			q.push(x);
		}
		else if (o == 2)
		{
			if (s.size() > 0)
			{
				cout << *s.begin() << endl;
				s.erase(s.begin());
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else
		{
			while (q.size())
			{
				s.insert(q.front());
				q.pop();
			}
		}
	}
}