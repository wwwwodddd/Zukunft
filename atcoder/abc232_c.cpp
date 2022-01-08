#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[9][9];
int b[9][9];
int p[9];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		b[x][y] = b[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	do
	{
	    bool f = 1;
	    for (int i = 1; i <= n; i++)
	    {
	        for (int j = 1; j <= n; j++)
	        {
	            if (a[i][j] != b[p[i]][p[j]])
	            {
	                f = 0;
	            }
	        }
	    }
	    if (f == 1)
	    {
	        cout << "Yes" << endl;
	        return 0;
	    }
	} while (next_permutation(p + 1, p + n + 1));
	cout << "No" << endl;
	return 0;
}
