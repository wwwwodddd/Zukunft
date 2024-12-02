#include <bits/stdc++.h>
using namespace std;
bitset<750> b[750]; // can be changed to int/bool b[750][750]
int n, x;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			scanf("%1d", &x); // read one digit
			b[i][j] = x;
		}
	}
	for (int j = 0; j < n; j++)
	{
		// each time, compute ans[0..j-1][j] in the same array b[][]
		for (int i = 0; i < j; i++)
		{
			for (int k = i + 1; k < j; k++)
			{
				// ^ means subtract,  & means multiply
				// b[i][j] = b[i][j] - (b[i][k] * b[k][j]);
				// consider all paths from  i  to  j  , the first *edge* is from  i  to  k  ,
				// then follow the paths from  k  to  j
				b[i][j] = b[i][j] ^ (b[i][k] & b[k][j]);
			}
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		z += b[i].count();
		// or another loop
	}
	printf("%d\n", z);
	return 0;
}