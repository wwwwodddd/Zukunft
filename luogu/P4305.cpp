#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
int t, n, x;
int main()
{
	t = read();
	for (int tt = 0; tt < t; tt++)
	{
		unordered_set<int> s;
		n = read();
		for (int i = 0; i < n; i++)
		{
			x = read();
			if (s.insert(x).second)
			{
				printf("%d ", x);
			}
		}
		printf("\n");
	}
	return 0;
}