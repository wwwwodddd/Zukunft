#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, x;
int s2[100020];
int s3[100020];
int s5[100020];
int gao(int d2, int d3, int d5, int x)
{
	switch(x){
		case 2:return d2;
		case 3:return d3;
		case 4:return d2 / 2;
		case 5:return d5;
		case 6:return min(d2, d3);
	}
	return 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		s2[i] = s2[i-1];
		s3[i] = s3[i-1];
		s5[i] = s5[i-1];
		scanf("%d", &x);
		while (x % 2 == 0)
		{
			s2[i]++;
			x /= 2;
		}
		while (x % 3 == 0)
		{
			s3[i]++;
			x /= 3;
		}
		while (x % 5 == 0)
		{
			s5[i]++;
			x /= 5;
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &l, &r, &x);
		l--;
		printf("%d\n", gao(s2[r] - s2[l], s3[r] - s3[l], s5[r] - s5[l], x));
	}
	return 0;
}