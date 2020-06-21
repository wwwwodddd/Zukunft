#include <bits/stdc++.h>
using namespace std;
map<string, int> g;
string s;
int n, o;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> o;
		if (o == 4)
		{
			cout << g.size() << endl;
		}
		else
		{
			cin >> s;
			if (o == 1)
			{
				cin >> g[s];
				cout << "OK" << endl;
			}
			else
			{
				auto it = g.find(s);
				if (it != g.end())
				{
					if (o == 2)
					{
						cout << g[s] << endl;
					}
					else
					{
						g.erase(s);
						cout << "Deleted successfully" << endl;
					}
				}
				else
				{
					cout << "Not found" << endl;
				}
			}
		}
	}
	return 0;
}