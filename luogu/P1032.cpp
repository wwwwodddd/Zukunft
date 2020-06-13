#include <bits/stdc++.h>
using namespace std;
int n;
string a, b, s[9], t[9];
void bfs()
{
	map<string, int> d;
	queue<string> q;
	q.push(a);
	d[a] = 0;
	while (q.size())
	{
		string u = q.front();
		q.pop();
		for (int i = 0; i < u.size(); i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i + s[j].size() <= u.size() && u.substr(i, s[j].size()) == s[j])
				{
					string v = u.substr(0, i) + t[j] + u.substr(i + s[j].size());
					if (v == b)
					{
						cout << d[u] + 1 << endl;
						return;
					}
					if (d.find(v) == d.end() && d[u] < 9)
					{
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}
		}
	}
	cout << "NO ANSWER!" << endl;
	return;
}
int main()
{
	cin >> a >> b;
	while (cin >> s[n] >> t[n])
	{
		n++;
	}
	bfs();
	return 0;
}