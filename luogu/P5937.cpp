#include <bits/stdc++.h>
using namespace std;
map<int, int> f;
int F(int x)
{
	return f.count(x) && f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
}
int n, m, x, y;
string s;
int main()
{
	cin >> n >> m;
	n++;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> s;
		x--;
		if (s[0] == 'e')
		{
			U(x, y);
			U(x + n, y + n);
		}
		else
		{
			U(x, y + n);
			U(x + n, y);			
		}
		if (F(x) == F(x + n))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << m << endl;
	return 0;
}
